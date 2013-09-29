#pragma once

#include <SDL2/SDL.h>
#include <cstdint>
#include <memory>
#include <iostream>

class CApplication
{
private:
   bool m_running;
   std::shared_ptr<SDL_Window> m_window;
   std::shared_ptr<SDL_Renderer> m_renderer;
   std::shared_ptr<SDL_Texture> m_texture; //also for testing delete me

public:
   CApplication();
   int32_t OnExecute();

   bool OnInit();
   void OnEvent(SDL_Event *sdlEvent);
   void OnUpdate();
   void OnRender();
   void OnCleanup();
};