#pragma once

#include <memory>

using std::shared_ptr;
using std::weak_ptr;

class CEntity;

class CComponent
{
public:
   CComponent();
   CComponent(shared_ptr<CEntity> entity);
   
   virtual CComponent *Create(shared_ptr<CEntity> gameObject);

   virtual ~CComponent();

   void RequestStart();
   void RequestUpdate();
   void RequestRender();

   void SetEnabled(bool enabled);
   bool IsEnabled();

protected:
   bool m_enabled;
   weak_ptr<CEntity> m_entity;

   virtual void Start();
   virtual void Update();
   virtual void Render();
};