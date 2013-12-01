#include "EntityFactory.h"
#include "CApplication.h"

shared_ptr<CEntity> EntityFactory::Instantiate(glm::vec2 position, float rotation)
{
   shared_ptr<CEntity> entity(new CEntity());
   entity->AddComponent<CTransform>();
   entity->Transform()->SetLocalPosition(position);
   entity->Transform()->SetLocalRotation(rotation);
   g_entities.AddEntity(entity);
   return entity;
}

shared_ptr<CEntity> EntityFactory::Instantiate(glm::vec2 position)
{
   return Instantiate(position, 0.0f);
}

shared_ptr<CEntity> EntityFactory::Instantiate()
{
   return Instantiate(glm::vec2(0.0f, 0.0f), 0.0f);
}
