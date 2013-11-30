#pragma once

#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include "CEntity.h"
#include "CComponent.h"
#include "CTransform.h"
#include "CBasicBulletController.h"
#include "CSprite.h"
#include "AjaxMath.h"
#include "CApplication.h"

class CBasicPlayerController : public CComponent
{
public:
   CBasicPlayerController();
   ~CBasicPlayerController();

protected:
   void Start() override;
   void Update(float dt) override;

private:
   glm::vec2 m_velocity;
   float m_speed;
   weak_ptr<CTransform> m_transform;

   void FireBullet();
};