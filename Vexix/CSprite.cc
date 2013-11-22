#include "CSprite.h"
#include "CApplication.h"

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

}

void CSprite::Update()
{

}

void CSprite::Render()
{
   SDL_RenderCopy(CApplication::Renderer().get(), m_texture.get(), nullptr, nullptr);
}