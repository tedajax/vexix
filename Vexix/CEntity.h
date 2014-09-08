#pragma once

#include <map>
#include <memory>
#include <cstring>
#include <string>
#include <typeindex>
#include "CComponent.h"
#include "CTransform.h"

using std::map;
using std::shared_ptr;
using std::weak_ptr;

class CTransform;

class CEntity : public std::enable_shared_from_this<CEntity>
{
public:
    CEntity();
    //todo: copy constructor

    ~CEntity();

    void SetEnabled(bool enabled);
    bool IsEnabled();

    std::string GetName();
    void SetName(std::string name);

    void Destroy();
    bool ShouldDestroy();

    void RequestStart();
    void RequestUpdate(float dt);
    void RequestRender();

    template <typename T>
    shared_ptr<T> GetComponent() {
        std::type_index index(typeid(T));
        if (m_components.count(index) != 0) {
            return std::static_pointer_cast<T>(m_components[index]);
        } else {
            return nullptr;
        }
    }

    template <typename T>
    shared_ptr<T> AddComponent() {
        shared_ptr<T> component(new T());

        const CComponent *ref = component.get();
        //not a component type
        if (!ref) { return nullptr; }

        std::type_index index = std::type_index(typeid(component));
        std::dynamic_pointer_cast<T, CComponent>(component)->SetEntity(shared_from_this());
        m_components[std::type_index(typeid(*component))] = component;

        return component;
    }

    shared_ptr<CTransform> Transform();

private:
    bool m_enabled;
    bool m_destroy;
    std::string m_name;
    shared_ptr<CTransform> m_transform;
    map<std::type_index, shared_ptr<CComponent>> m_components;
};