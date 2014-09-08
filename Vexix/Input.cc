#include "Input.h"

Input::Input() {

}

Input::~Input() {

}

uint8_t Input::GetKey(uint32_t key) {
    return m_currKeyStates[key];
}

uint8_t Input::GetKeyDown(uint32_t key) {
    return m_currKeyStates[key] && !m_prevKeyStates[key];
}

uint8_t Input::GetKeyUp(uint32_t key) {
    return !m_currKeyStates[key] && m_prevKeyStates[key];
}

void Input::Update() {
    std::copy(m_currKeyStates.begin(), m_currKeyStates.end(), m_prevKeyStates.begin());
    const Uint8 *keys = SDL_GetKeyboardState(nullptr);
    std::copy(keys, keys + SDL_NUM_SCANCODES, m_currKeyStates.begin());
}