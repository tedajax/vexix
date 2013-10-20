#pragma once

#include <memory>

using std::shared_ptr;
using std::weak_ptr;

class CEntity;

class CComponent
{
public:
   CComponent();
   CComponent(shared_ptr<CEntity> gameObject);
   
   virtual CComponent *Create(shared_ptr<CEntity> gameObject);

   virtual ~CComponent();

   virtual void Start();
   virtual void Update();
   virtual void Render();

protected:
   weak_ptr<CEntity> m_gameObject;
};