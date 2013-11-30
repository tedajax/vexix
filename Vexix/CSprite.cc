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
   UpdateTextureData(texture);
}

void CSprite::SetTexture(std::string resourceName)
{
   auto tex = g_resources.Get<Texture>(resourceName);
   if (tex) {
      UpdateTextureData(tex->GetTexture());
   }
   return;
}

void CSprite::UpdateTextureData(shared_ptr<SDL_Texture> texture)
{
   if (texture) {
      m_texture = texture;

      SDL_QueryTexture(m_texture.get(), nullptr, nullptr, &m_width, &m_height);
   }
}

shared_ptr<SDL_Texture> CSprite::GetTexture() const
{
   return m_texture;
}

void CSprite::Start()
{
   m_transform = GetComponent<CTransform>();
}

SDL_Rect CSprite::RectFromTransform()
{
   SDL_Rect result;

   result.x = 0;
   result.y = 0;
   result.w = m_width;
   result.h = m_height;

   if (auto transform = m_transform.lock()) {
      result.x = (int32_t)transform->GetLocalPosition().x;
      result.y = (int32_t)transform->GetLocalPosition().y;
      result.w = (int32_t)(result.w * transform->GetLocalScale().x);
      result.h = (int32_t)(result.h * transform->GetLocalScale().y);
   }
   
   return result;
}

void CSprite::Render()
{
   SDL_Rect posRect = RectFromTransform();
   float rotation = 0.0f;
   if (auto transform = m_transform.lock()) {
      rotation = transform->GetLocalRotation();
   }
   SDL_RenderCopyEx(g_application.Renderer().get(),
                    m_texture.get(),
                    nullptr,
                    &posRect,
                    rotation,
                    nullptr,
                    SDL_FLIP_NONE);
}