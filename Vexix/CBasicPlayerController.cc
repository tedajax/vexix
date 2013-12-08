#include "CBasicPlayerController.h"

CBasicPlayerController::CBasicPlayerController()
{

}

CBasicPlayerController::~CBasicPlayerController()
{

}

void CBasicPlayerController::Start()
{
   Transform()->SetLocalPosition(glm::vec2(32.0f, 296.0f));

   m_speed = 640.0f;
}

void CBasicPlayerController::Update(float dt)
{
   m_velocity = ajx::vec2::zero;

   if (g_input.GetKey(SDL_SCANCODE_RIGHT)) {
      m_velocity += ajx::vec2::unit_x * m_speed;
   }
   if (g_input.GetKey(SDL_SCANCODE_LEFT)) {
      m_velocity -= ajx::vec2::unit_x * m_speed;
   }

   if (g_input.GetKey(SDL_SCANCODE_UP)) {
      m_velocity -= ajx::vec2::unit_y * m_speed;
   }
   if (g_input.GetKey(SDL_SCANCODE_DOWN)) {
      m_velocity += ajx::vec2::unit_y * m_speed;
   }

   Transform()->Move(m_velocity * dt);
   
   if (g_input.GetKey(SDL_SCANCODE_Z)) {
      FireBullet();
   }
}

void CBasicPlayerController::FireBullet()
{
   auto entity = shared_ptr<CEntity>(new CEntity());
   entity->SetName("Bullet");
   auto entityTransform = entity->AddComponent<CTransform>();
   auto sprite = entity->AddComponent<CSprite>();
   entity->AddComponent<CBasicBulletController>();

   sprite->SetTexture("bullet.png");

   if (auto transform = GetComponent<CTransform>()) {
      glm::vec2 bulletStartPos = transform->GetLocalPosition() + glm::vec2(114.0f, 40.0f);
      entityTransform->SetLocalPosition(bulletStartPos);
   }

   g_entities.AddEntity(entity);
}
