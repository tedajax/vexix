#pragma once

#include <map>
#include <memory>
#include <cstring>
#include <string>
#include <typeindex>
#include "CComponent.h"

using std::map;
using std::shared_ptr;
using std::weak_ptr;

class CEntity
{
public:
   CEntity();
   //todo: copy constructor
   
   ~CEntity();

   void SetEnabled(bool enabled);
   bool IsEnabled();

   std::string GetName();
   void SetName(std::string name);

   template <typename T>
   shared_ptr<T> GetComponent()
   {
      std::type_index index(typeid(T));
      if (m_components.count(index) != 0) {
         return std::static_pointer_cast<T>(m_components[index]);
      } else {
         return nullptr;
      }
   }

   template <typename T>
   void AddComponent(shared_ptr<T> component)
   {
      std::type_index index = std::type_index(typeid(component));
      m_components[std::type_index(typeid(*component))] = component;
   }
   
private:
   bool m_enabled;
   std::string m_name;
   map<std::type_index, shared_ptr<CComponent>> m_components;
};