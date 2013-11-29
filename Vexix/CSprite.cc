#include "CSprite.h"
#include "CApplication.h"
#include <SDL2/SDL.h>

CSprite::CSprite()
{

}

CSprite::CSprite(const CSprite &other)
{
   this->SetTexture(other.GetTexture());
}

CSprite::~CSprite()
{

}

void CSprite::SetTexture(shared_ptr<SDL_Texture> texture)
{
   m_texture = texture;
}

void CSprite::SetTexture(std::string resourceName)
{
   //todo
   return;
}

shared_ptr<SDL_Texture> CSprite::GetTexture() const
{
   return m_texture;
}

void CSprite::Start()
{
   m_transform = GetComponent<CTransform>();
}

void CSprite::Update()
{
   if (auto transform = m_transform.lock()) {
      transform->Move(glm::vec2(0.0f, 1.0f));
   }
}

SDL_Rect CSprite::RectFromTransform()
{
   SDL_Rect result;

   if (auto transform = m_transform.lock()) {
      result.x = (int32_t)transform->GetLocalPosition().x;
      result.y = (int32_t)transform->GetLocalPosition().y;
   } else {
      result.x = 0;
      result.y = 0;
   }

   SDL_QueryTexture(m_texture.get(), nullptr, nullptr, &result.w, &result.h);
   return result;
}

void CSprite::Render()
{
   SDL_Rect posRect = RectFromTransform();
   SDL_RenderCopy(g_application.Renderer().get(), m_texture.get(), nullptr, &posRect);
}