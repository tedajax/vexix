#pragma once

#include <map>
#include <memory>
#include <map>
#include <fstream>
#include <string>
#include <cstdint>
#include <type_traits>
#include "AjaxUtil.h"

using std::string;
using std::map;
using std::shared_ptr;

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
      NOT_VALID_RESOURCE_TYPE = 3
   };

   template <class T>
   ResourceLoadResult LoadResource(const string &filename)
   {
      shared_ptr<T> newResource = new T();

      const Resource &ref = newResource;
      if (!ref) { return NOT_VALID_RESOURCE_TYPE; }

      string assetPath = DEFAULT_ASSET_PATH + filename;
      
      ResourceLoadResult loadResult = newResource->Load(assetPath);
      if (loadResult == SUCCESS) {
         m_resources.insert(m_currentId, newResource);
         ++m_currentId;
      }

      return loadResult;
   }

private:
   map<uint32_t, shared_ptr<Resource>> m_resources;
   uint32_t m_currentId;
};

class Resource
{
public:
   Resource();
   ~Resource();

   virtual ResourceManager::ResourceLoadResult Load(string filename);

protected:
   string m_name;
   string m_filename;
   string m_path;
};

class Texture : public Resource
{
public:
   ResourceManager::ResourceLoadResult Load(string filename);


};