#include "CBasicBulletController.h"

CBasicBulletController::CBasicBulletController()
{

}

CBasicBulletController::~CBasicBulletController()
{

}

void CBasicBulletController::Start()
{
   m_speed = 1000;
}

void CBasicBulletController::Update(float dt)
{
   if (auto transform = GetComponent<CTransform>()) {
      transform->Move(glm::vec2(m_speed * dt, 0.0f));
   }
}