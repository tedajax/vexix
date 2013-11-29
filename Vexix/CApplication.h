#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdint>
#include <memory>
#include <iostream>
#include "AjaxUtil.h"
#include "ResourceManager.h"
#include "CEntityManager.h"
#include "Input.h"

class CApplication
{
private:
   bool m_running;
   std::shared_ptr<SDL_Window> m_window;
   std::shared_ptr<SDL_Renderer> m_renderer;
   CEntityManager m_entities;

public:
   CApplication();
   int32_t OnExecute();

   bool OnInit();
   void OnEvent(SDL_Event *sdlEvent);
   void OnUpdate();
   void OnRender();
   void OnCleanup();

   std::shared_ptr<SDL_Window> Window();
   std::shared_ptr<SDL_Renderer> Renderer();
};

extern CApplication g_application;
extern ResourceManager g_resources;
extern Input g_input;