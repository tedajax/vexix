#include "CComponent.h"

CComponent::CComponent()
{

}

CComponent::CComponent(shared_ptr<CEntity> gameObject)
{
   m_gameObject = gameObject;
}

CComponent *CComponent::Create(shared_ptr<CEntity> gameObject)
{
   return new CComponent();
}

