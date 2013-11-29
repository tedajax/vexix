#include "CApplication.h"
#include "CEntity.h"
#include "CSprite.h"
#include "CTransform.h"

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
   entity->AddComponent<CTransform>(shared_ptr<CTransform>(new CTransform()));
   m_entities.AddEntity(entity);
   
   g_resources.LoadResource<Texture>("hello.png");
   shared_ptr<SDL_Texture> texture = g_resources.Get<Texture>("hello.png")->GetTexture();
   sprite->SetTexture(texture);

   m_entities.Start();

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
   LOAD_MSG("Initializing SDL")
   if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }
   DONE

   LOAD_MSG("Initializing SDL_image")
   int32_t imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
   if (!(IMG_Init(imgFlags) & imgFlags)) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }
   DONE

   LOAD_MSG("Creating window")
   m_window = std::shared_ptr<SDL_Window>(SDL_CreateWindow("Vexix", 100, 100, 640, 480, SDL_WINDOW_SHOWN), SDL_DestroyWindow);
   if (m_window == nullptr) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }
   DONE

   LOAD_MSG("Creating renderer")
   m_renderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer);
   if (m_renderer == nullptr) {
      std::cout << SDL_GetError() << std::endl;
      return false;
   }   
   DONE
   
   return true;
}

void CApplication::OnEvent(SDL_Event *sdlEvent)
{
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

void CApplication::OnUpdate()
{
   m_entities.Update();
}

void CApplication::OnRender()
{
   SDL_RenderClear(m_renderer.get());
   m_entities.Render();
   SDL_RenderPresent(m_renderer.get());
}

void CApplication::OnCleanup()
{
   SDL_Quit();
}

shared_ptr<SDL_Window> CApplication::Window() { return m_window; }
shared_ptr<SDL_Renderer> CApplication::Renderer() { return m_renderer; }

CApplication g_application;
ResourceManager g_resources;