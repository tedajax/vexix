#include "CBasicPlayerController.h"

CBasicPlayerController::CBasicPlayerController()
{

}

CBasicPlayerController::~CBasicPlayerController()
{

}

void CBasicPlayerController::Start()
{
   m_transform = GetComponent<CTransform>();
   m_speed = 10.0f;
}

void CBasicPlayerController::Update()
{
   m_velocity = ajx::vec2::zero;

   if (g_input.GetKey(SDLK_RIGHT)) {
      m_velocity += ajx::vec2::unit_x * m_speed;
   }
   if (g_input.GetKey(SDLK_LEFT)) {
      m_velocity -= ajx::vec2::unit_x * m_speed;
   }

   if (g_input.GetKey(SDLK_UP)) {
      m_velocity -= ajx::vec2::unit_y * m_speed;
   }
   if (g_input.GetKey(SDLK_DOWN)) {
      m_velocity += ajx::vec2::unit_y * m_speed;
   }

   if (auto transform = m_transform.lock()) {
      transform->Move(m_velocity);
   }
}
