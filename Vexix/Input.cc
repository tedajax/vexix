#include "Input.h"

Input::Input()
{

}

Input::~Input()
{

}

bool Input::GetKey(uint8_t key)
{
   return m_currKeyStates[key];
}

bool Input::GetKeyDown(uint8_t key)
{
   return m_currKeyStates[key] && !m_prevKeyStates[key];
}

bool Input::GetKeyUp(uint8_t key)
{
   return !m_currKeyStates[key] && m_prevKeyStates[key];
}

void Input::Update()
{
   std::copy(m_currKeyStates.begin(), m_currKeyStates.end(), m_prevKeyStates.begin());
   const Uint8 *keys = SDL_GetKeyboardState(nullptr);
   std::copy(keys, keys + SDL_NUM_SCANCODES, m_currKeyStates.begin());
}