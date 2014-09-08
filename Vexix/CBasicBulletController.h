#pragma once

#include <memory>
#include "CComponent.h"
#include "CTransform.h"
#include "CEntity.h"

class CBasicBulletController : public CComponent
{
public:
    CBasicBulletController();
    ~CBasicBulletController();

protected:
    void Start() override;
    void Update(float dt) override;

private:
    float m_speed;
};