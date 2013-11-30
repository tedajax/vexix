#pragma once

#include <memory>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include "AjaxUtil.h"
#include "CEntity.h"

using std::vector;
using std::queue;
using std::shared_ptr;
using std::string;

class CEntityManager
{
public:
   CEntityManager();
   ~CEntityManager();

   shared_ptr<CEntity> AddEntityImmediately(shared_ptr<CEntity> entity);
   shared_ptr<CEntity> AddEntity(shared_ptr<CEntity> entity);
   void RemoveEntity(shared_ptr<CEntity> entity);

   //finds first entity with name
   shared_ptr<CEntity> FindEntity(string name);
   //finds all entities with name
   vector<shared_ptr<CEntity>> FindEntities(string name);

   void Start();
   void Update(float dt);
   void Render();

private:
   vector<shared_ptr<CEntity>> m_entities;
   queue<shared_ptr<CEntity>> m_addQueue;
   queue<shared_ptr<CEntity>> m_removeQueue;
};