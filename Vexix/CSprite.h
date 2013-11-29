#pragma once

#include <memory>
#include <string>
#include <glm/glm.hpp>
#include <SDL2/SDL.h>
#include "CComponent.h"
#include "CTransform.h"
#include "AjaxMath.h"

using std::shared_ptr;
using std::weak_ptr;
using namespace ajx;

class CSprite : public CComponent
{
public:
   CSprite();
   CSprite(const CSprite &other);

   ~CSprite();

   void SetTexture(shared_ptr<SDL_Texture> texture);
   void SetTexture(std::string resourceName);
   shared_ptr<SDL_Texture> GetTexture() const;
  
protected:
   void Start() override;
   void Update() override;
   void Render() override;

private:
   shared_ptr<SDL_Texture> m_texture;
   weak_ptr<CTransform> m_transform;

   SDL_Rect RectFromTransform();
};