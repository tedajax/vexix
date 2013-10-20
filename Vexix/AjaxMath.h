#pragma once

#include <glm/glm.hpp>

//various shortcuts I've made for some math stuff

namespace ajx
{
   namespace vec2
   {
      static glm::vec2 zero   = glm::vec2( 0.0f,  0.0f);
      static glm::vec2 one    = glm::vec2( 1.0f,  1.0f);
      static glm::vec2 unit_x = glm::vec2( 1.0f,  0.0f);
      static glm::vec2 unit_y = glm::vec2( 0.0f,  1.0f);
   }

   namespace vec3
   {
      static glm::vec3 zero    = glm::vec3( 0.0f,  0.0f,  0.0f);
      static glm::vec3 one     = glm::vec3( 1.0f,  1.0f,  1.0f);
      static glm::vec3 right   = glm::vec3( 1.0f,  0.0f,  0.0f);
      static glm::vec3 up      = glm::vec3( 0.0f,  1.0f,  0.0f);
      static glm::vec3 forward = glm::vec3( 0.0f,  0.0f, -1.0f);
   }

   namespace mat3
   {
      static glm::mat3 identity = glm::mat3(1.0f);
   }

   namespace mat4
   {
      static glm::mat4 identity = glm::mat4(1.0f);
   }
}