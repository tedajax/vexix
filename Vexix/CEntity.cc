#include "CEntity.h"

CEntity::CEntity()
{

}

CEntity::~CEntity()
{

}

void CEntity::SetEnabled(bool enabled) { m_enabled = enabled; }
bool CEntity::IsEnabled() { return m_enabled; }

std::string CEntity::GetName() { return m_name; }
void CEntity::SetName(std::string name) { m_name = name; }

void CEntity::RequestStart()
{
   if (m_enabled) {
      for (auto &kvp : m_components) {
         kvp.second->RequestStart();
      }
   }
}

void CEntity::RequestUpdate()
{
   if (m_enabled) {
      for (auto &kvp : m_components) {
         kvp.second->RequestUpdate();
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