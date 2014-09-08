#pragma once

#include <memory>
#include "AjaxUtil.h"

using std::shared_ptr;
using std::weak_ptr;

class CEntity;
class CTransform;

class CComponent
{
public:
    CComponent();
    CComponent(shared_ptr<CEntity> entity);

    virtual CComponent *Create(shared_ptr<CEntity> entity);
    virtual ~CComponent();

    template <typename T>
    shared_ptr<T> GetComponent() {
        if (auto entity = m_entity.lock()) {
            return entity->GetComponent<T>();
        }
        return nullptr;
    }

    shared_ptr<CTransform> Transform();

    void RequestStart();
    void RequestUpdate(float dt);
    void RequestRender();

    void SetEnabled(bool enabled);
    bool IsEnabled();

    void SetEntity(shared_ptr<CEntity> entity);

protected:
    bool m_enabled;
    weak_ptr<CEntity> m_entity;

    virtual void Start();
    virtual void Update(float dt);
    virtual void Render();
};