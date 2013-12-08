#include "CEntityManager.h"

CEntityManager::CEntityManager()
{
   m_entityAddMode = Immediate;
}

CEntityManager::~CEntityManager()
{
   m_entities.clear();
}

shared_ptr<CEntity> CEntityManager::AddEntityImmediately(shared_ptr<CEntity> entity)
{
   if (entity) {
      AddEntityToList(entity);
   }

   return entity;
}

shared_ptr<CEntity> CEntityManager::AddEntity(shared_ptr<CEntity> entity)
{
   if (m_entityAddMode == Immediate) {
      return AddEntityImmediately(entity);
   }

   if (entity) {
      m_addQueue.push(entity);
   }

   return entity;
}

void CEntityManager::RemoveEntity(shared_ptr<CEntity> entity)
{
   m_entities.resize(std::remove(m_entities.begin(), m_entities.end(), entity) - m_entities.begin());
}

void CEntityManager::Start()
{
   for (auto &e : m_entities) {
      if (!e) { continue; }
      e->RequestStart();
   }

   m_entityAddMode = Queued;
}

void CEntityManager::Update(float dt)
{
   uint32_t index = 0;
   for (auto &e : m_entities) {
      if (e) {
         e->RequestUpdate(dt);
         if (e->ShouldDestroy()) {
            m_removeQueue.push(index);
         }
      }
      ++index;
   }
   
   RemoveFlaggedEntities();
   AddQueuedEntities();
}

void CEntityManager::RemoveFlaggedEntities()
{
   const uint32_t MAX_REMOVED_PER_FRAME = 100000;
   uint32_t removedThisFrame = 0;
   while (m_removeQueue.size() > 0 && removedThisFrame < MAX_REMOVED_PER_FRAME) {
      auto index = m_removeQueue.front();
      auto e = m_entities[index];
      m_entities[index] = nullptr;
      m_availableIndices.push(index);
      m_removeQueue.pop();
      ++removedThisFrame;
   }
}

void CEntityManager::AddQueuedEntities()
{
   while (m_addQueue.size() > 0) {
      auto e = m_addQueue.front();
      e->RequestStart();
      AddEntityToList(e);
      m_addQueue.pop();
   }
}

void CEntityManager::AddEntityToList(shared_ptr<CEntity> entity)
{
   if (m_availableIndices.size() > 0) {
      uint32_t index = m_availableIndices.top();
      m_availableIndices.pop();
      m_entities[index] = entity;
   } else {
      m_entities.push_back(entity);
   }
}

void CEntityManager::Render()
{
   for (auto &e : m_entities) {
      if (!e) { continue; }
      e->RequestRender();
   }
}

shared_ptr<CEntity> CEntityManager::FindEntity(string name)
{
   for (auto &e : m_entities) {
      if (!e) { continue; }
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
      if (!e) { continue; }
      if (e->GetName() == name) {
         results.push_back(e);
      }
   }
   return results;
}