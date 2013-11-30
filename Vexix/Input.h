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

   uint8_t GetKey(uint32_t key);
   uint8_t GetKeyDown(uint32_t key);
   uint8_t GetKeyUp(uint32_t key);

   void Update();

private:
   std::array<uint32_t, SDL_NUM_SCANCODES> m_prevKeyStates;
   std::array<uint32_t, SDL_NUM_SCANCODES> m_currKeyStates;
};