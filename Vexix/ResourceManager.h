#pragma once

#include <map>
#include <memory>
#include <map>
#include <fstream>
#include <string>
#include <cstdint>
#include <type_traits>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "AjaxUtil.h"

using std::string;
using std::map;
using std::shared_ptr;
using std::weak_ptr;

const string DEFAULT_ASSET_PATH = "Assets/";

class Resource;

template <class T> struct is_resource : false_type {};

class ResourceManager
{
public:
   ResourceManager();
   ~ResourceManager();

   enum ResourceLoadResult {
      SUCCESS = 0,
      FILE_NOT_FOUND = 1,
      FILE_ALREADY_LOADED = 2,
      NOT_VALID_RESOURCE_TYPE = 3,
      FILE_PROCESSING_ERROR = 4
   };

   template <class T>
   ResourceLoadResult LoadResource(const string &filename)
   {
      shared_ptr<T> newResource = shared_ptr<T>(new T());

      const Resource *ref = newResource.get();
      if (!ref) { return NOT_VALID_RESOURCE_TYPE; }

      string assetPath = DEFAULT_ASSET_PATH + filename;
      
      ResourceLoadResult loadResult = newResource->Load(assetPath);
      if (loadResult == SUCCESS) {         
         auto insResult = m_resources.insert(std::make_pair(filename, newResource));
         if (!insResult.second) {
            return FILE_ALREADY_LOADED;
         }

         newResource->SetResourceID(m_currentId);         
         ++m_currentId;
      }

      return loadResult;
   }

   template <class T>
   shared_ptr<T> Get(const string &filename)
   {
      if (m_resources.find(filename) != m_resources.end()) {
         return std::dynamic_pointer_cast<T>(m_resources[filename]);
      } else {
         return nullptr;
      }
   }

private:
   map<string, shared_ptr<Resource>> m_resources;
   uint32_t m_currentId;
};

class Resource
{
public:
   Resource();
   virtual ~Resource();

   virtual ResourceManager::ResourceLoadResult Load(string filename);

   string GetName();
   string GetPath();
   string GetFullFileName();
   uint32_t GetResourceID();
   void SetResourceID(uint32_t id);

protected:
   void GenerateNamesFromPath(string filename);

   string m_name;
   string m_filename;
   string m_path;
   uint32_t m_id;
};

class Texture : public Resource
{
public:
   Texture();
   ~Texture();

   ResourceManager::ResourceLoadResult Load(string filename);

   shared_ptr<SDL_Texture> GetTexture();

private:
   shared_ptr<SDL_Texture> m_texture;
};