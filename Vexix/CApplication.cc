#include "CApplication.h"
#include "CEntity.h"
#include "CSprite.h"
#include "CTransform.h"

shared_ptr<SDL_Renderer> CApplication::s_renderer;

CApplication::CApplication()
{
   m_running = true;
}

int32_t CApplication::OnExecute()
{
   if (OnInit() == false) {
      return -1;
   }

   shared_ptr<CEntity> entity = shared_ptr<CEntity>(new CEntity());
   entity->AddComponent<CSprite>(shared_ptr<CSprite>(new CSprite()));
   shared_ptr<CSprite> sprite = entity->GetComponent<CSprite>();
   
   std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*> bitmap = std::unique_ptr<SDL_Surface, decltype(SDL_FreeSurface)*>(SDL_LoadBMP("hello.bmp"), SDL_FreeSurface);
   if (bitmap == nullptr) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }

   shared_ptr<SDL_Texture> texture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(s_renderer.get(), bitmap.get()), SDL_DestroyTexture);
   sprite->SetTexture(texture);

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

   s_renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer);

   if (s_renderer == nullptr) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }   
   
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
   SDL_RenderClear(s_renderer.get());
   
   SDL_RenderPresent(s_renderer.get());
}

void CApplication::OnCleanup()
{
   SDL_Quit();
}

shared_ptr<SDL_Renderer> CApplication::Renderer() { return s_renderer; }