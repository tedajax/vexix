#pragma once

#include <memory>

using std::shared_ptr;
using std::weak_ptr;

class CEntity;

class CComponent
{
protected:
   weak_ptr<CEntity> m_gameObject;
};