#include "CApplication.h"

CApplication::CApplication()
{
   m_running = true;
}

int32_t CApplication::OnExecute()
{
   if (OnInit() == false) {
      return -1;
   }

   SDL_Event sdlEvent;
   while (m_running) {
      while (SDL_PollEvent(&sdlEvent)) {
         OnEvent(&sdlEvent);
      }

      OnUpdate();
      OnRender();
   }

   OnCleanup();

   return 0;
}

bool CApplication::OnInit()
{
   if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }

   m_window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Vexix", 100, 100, 640, 480, SDL_WINDOW_SHOWN), SDL_DestroyWindow);
   if (m_window == nullptr) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }

   m_renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer);

   if (m_renderer == nullptr) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }

   std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*> m_bitmap = std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*>(SDL_LoadBMP("hello.bmp"), SDL_FreeSurface);
   if (m_bitmap == nullptr) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }

   m_texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(m_renderer.get(), m_bitmap.get()), SDL_DestroyTexture);
   
   return true;
}

void CApplication::OnEvent(SDL_Event *sdlEvent)
{
   while (SDL_PollEvent(sdlEvent)) {
      switch (sdlEvent->type) {
      case SDL_QUIT:
         m_running = false;
         break;

      case SDL_KEYDOWN:
         if (sdlEvent->key.keysym.sym == SDLK_ESCAPE) {
            m_running = false;
         }
         break;
      }
   }
}

void CApplication::OnUpdate()
{

}

void CApplication::OnRender()
{
   SDL_RenderClear(m_renderer.get());
   SDL_RenderCopy(m_renderer.get(), m_texture.get(), nullptr, nullptr);
   SDL_RenderPresent(m_renderer.get());
}

void CApplication::OnCleanup()
{
   SDL_Quit();
}

