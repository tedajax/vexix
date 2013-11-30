#include "CComponent.h"

CComponent::CComponent()
{

}

CComponent::CComponent(shared_ptr<CEntity> entity)
{
   m_entity = entity;
}

CComponent *CComponent::Create(shared_ptr<CEntity> entity)
{
   return new CComponent(entity);
}

CComponent::~CComponent()
{

}

void CComponent::SetEnabled(bool enabled) { m_enabled = enabled; }
bool CComponent::IsEnabled() { return m_enabled; }

void CComponent::SetEntity(shared_ptr<CEntity> entity) { m_entity = entity; }

void CComponent::RequestStart()
{
   if (m_enabled) {
      this->Start();
   }
}

void CComponent::RequestUpdate(float dt)
{
   if (m_enabled) {
      this->Update(dt);
   }
}

void CComponent::RequestRender()
{
   if (m_enabled) {
      this->Render();
   }
}

void CComponent::Start()
{
   
}

void CComponent::Update(float dt)
{

}

void CComponent::Render()
{

}