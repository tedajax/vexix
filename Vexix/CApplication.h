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
   static std::shared_ptr<SDL_Renderer> s_renderer;

public:
   CApplication();
   int32_t OnExecute();

   bool OnInit();
   void OnEvent(SDL_Event *sdlEvent);
   void OnUpdate();
   void OnRender();
   void OnCleanup();

   static std::shared_ptr<SDL_Renderer> Renderer();
};