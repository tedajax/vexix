#include <memory>

#include "CEntity.h"
#include "Components.h"

using std::shared_ptr;

class CEntityFactory
{
public:
   static shared_ptr<CEntity> Instantiate(glm::vec2 position, float rotation);
   static shared_ptr<CEntity> Instantiate(glm::vec2 position);
   static shared_ptr<CEntity> Instantiate();
};

