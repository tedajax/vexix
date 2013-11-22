#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
   m_currentId = 1;
}

ResourceManager::~ResourceManager()
{
   //todo
}

Resource::Resource()
{

}

Resource::~Resource()
{

}

ResourceManager::ResourceLoadResult Resource::Load(string filename)
{
   std::vector<string> tokens = ajx::split(filename, '/');
   
}