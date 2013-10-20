#pragma once

#include <memory>
#include "CComponent.h"
#include <glm/glm.hpp>

using std::shared_ptr;
using std::weak_ptr;

class CTransform : public CComponent
{
public:
   CTransform();
   CTransform(const CTransform &other);
   CTransform(glm::vec2 position);
   CTransform(glm::vec2 position, float rotation);
   CTransform(glm::vec2 position, float rotation, glm::vec2 scale);



private:
   glm::vec2   m_position;
   glm::vec2   m_scale;
   glm::mat3x3 m_world;
   float       m_rotation;
};