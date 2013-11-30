#include "CEntityManager.h"

CEntityManager::CEntityManager()
{

}

CEntityManager::~CEntityManager()
{
   m_entities.clear();
}

bool CEntityManager::AddEntity(shared_ptr<CEntity> entity)
{
   if (entity) {
      m_entities.push_back(entity);
      return true;
   }

   return false;
}

void CEntityManager::RemoveEntity(shared_ptr<CEntity> entity)
{
   m_entities.resize(std::remove(m_entities.begin(), m_entities.end(), entity) - m_entities.begin());
}

void CEntityManager::Start()
{
   for (auto &e : m_entities) {
      e->RequestStart();
   }
}

void CEntityManager::Update(float dt)
{
   for (auto &e : m_entities) {
      e->RequestUpdate(dt);
   }
}

void CEntityManager::Render()
{
   for (auto &e : m_entities) {
      e->RequestRender();
   }
}

shared_ptr<CEntity> CEntityManager::FindEntity(string name)
{
   for (auto &e : m_entities) {
      if (e->GetName() == name) {
         return e;
      }
   }
   return nullptr;
}

vector<shared_ptr<CEntity>> CEntityManager::FindEntities(string name)
{
   vector<shared_ptr<CEntity>> results;
   for (auto &e : m_entities) {
      if (e->GetName() == name) {
         results.push_back(e);
      }
   }
   return results;
}