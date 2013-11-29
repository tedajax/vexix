#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <array>
#include <algorithm>

class Input
{
public:
   Input();
   ~Input();

   bool GetKey(uint8_t key);
   bool GetKeyDown(uint8_t key);
   bool GetKeyUp(uint8_t key);

   void Update();

private:
   std::array<uint8_t, SDL_NUM_SCANCODES> m_prevKeyStates;
   std::array<uint8_t, SDL_NUM_SCANCODES> m_currKeyStates;
};