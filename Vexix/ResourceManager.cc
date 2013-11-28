#include "ResourceManager.h"
#include "CApplication.h"

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

string Resource::GetName() { return m_name; }
string Resource::GetPath() { return m_path; }
string Resource::GetFullFileName() { return m_filename; }
uint32_t Resource::GetResourceID() { return m_id; }
void Resource::SetResourceID(uint32_t id) { m_id = id; }

ResourceManager::ResourceLoadResult Resource::Load(string filename)
{
   GenerateNamesFromPath(filename);
   return ResourceManager::SUCCESS;
}

void Resource::GenerateNamesFromPath(string filename)
{
   m_filename = filename;

   std::vector<string> tokens = ajx::split(filename, '/');
   m_name = tokens.back();

   m_path = "";
   for (auto itr = tokens.begin(); itr != tokens.end() - 1; ++itr) {
      m_path += (*itr) + "/";
   }
}

Texture::Texture()
{

}

Texture::~Texture()
{

}

ResourceManager::ResourceLoadResult Texture::Load(string filename)
{
   LOAD_MSG("Loading " + filename)

   Resource::Load(filename);
   
   auto rawImage = std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*>(IMG_Load(filename.c_str()), 
                                                                            SDL_FreeSurface);
   if (!rawImage) {
      FAILED
      std::cout << SDL_GetError() << std::endl;
      return ResourceManager::FILE_NOT_FOUND;
   }
   SDL_PixelFormat *format = SDL_GetWindowSurface(g_application.Window().get())->format;
   auto optimizedImage = std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*>(SDL_ConvertSurface(rawImage.get(), format, 0),
                                                                                  SDL_FreeSurface);
   if (!optimizedImage) {
      FAILED
      std::cout << SDL_GetError() << std::endl;
      return ResourceManager::FILE_PROCESSING_ERROR;
   }

   SDL_Renderer *renderer = g_application.Renderer().get();
   m_texture = shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(renderer, optimizedImage.get()), SDL_DestroyTexture);
   if (!m_texture) {
      FAILED
      std::cout << SDL_GetError() << std::endl;
      return ResourceManager::FILE_PROCESSING_ERROR;
   }

   DONE

   return ResourceManager::SUCCESS;
}

shared_ptr<SDL_Texture> Texture::GetTexture() { return m_texture; }