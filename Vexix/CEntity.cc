#include "CEntity.h"

CEntity::CEntity()
{
   m_destroy = false;
}

CEntity::~CEntity()
{

}

void CEntity::SetEnabled(bool enabled) { m_enabled = enabled; }
bool CEntity::IsEnabled() { return m_enabled; }

void CEntity::Destroy() { m_destroy = true; }
bool CEntity::ShouldDestroy() { return m_destroy; }

std::string CEntity::GetName() { return m_name; }
void CEntity::SetName(std::string name) { m_name = name; }

shared_ptr<CTransform> CEntity::Transform()
{
   if (!m_transform) {
      m_transform = GetComponent<CTransform>();
   }
   
   return m_transform;
}

void CEntity::RequestStart()
{
   if (m_enabled) {
      for (auto &kvp : m_components) {
         kvp.second->RequestStart();
      }
   }
}

void CEntity::RequestUpdate(float dt)
{
   if (m_enabled) {
      for (auto &kvp : m_components) {
         kvp.second->RequestUpdate(dt);
      }
   }
}

void CEntity::RequestRender()
{
   if (m_enabled) {
      for (auto &kvp : m_components) {
         kvp.second->RequestRender();
      }
   }
}