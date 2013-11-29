#pragma once

#include <memory>
#include <vector>
#include "CComponent.h"
#include "AjaxMath.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using std::shared_ptr;
using std::weak_ptr;
using std::vector;

using namespace ajx;

class CTransform;
typedef weak_ptr<CTransform> CTransformWeakPtr;
typedef vector<CTransformWeakPtr> CTransformList;

//todo: 

class CTransform : public CComponent
{
public:
   CTransform();
   CTransform(const CTransform &other);
   CTransform(glm::vec2 position);
   CTransform(glm::vec2 position, float rotation);
   CTransform(glm::vec2 position, float rotation, glm::vec2 scale);

   ~CTransform();

   /*CTransformWeakPtr GetParent() const;
   bool SetParent(shared_ptr<CTransform> parent);*/

   glm::vec2 GetLocalPosition() const;
   glm::vec2 GetLocalScale() const;
   float GetLocalRotation() const;
   glm::mat3 GetLocalWorldMatrix() const;

   void Move(glm::vec2 velocity);
   void Rotate(float angVelocity);
   void Stretch(float sclVelocity);

   void SetLocalPosition(glm::vec2 position);
   void SetLocalRotation(float rotation);
   void SetLocalScale(glm::vec2 scale);

private:
   glm::vec2         m_localPosition;
   float             m_localRotation;
   glm::vec2         m_localScale;   
   glm::mat3         m_localWorld;

   /*CTransformWeakPtr m_parent;
   CTransformList    m_children;*/

   glm::mat3 BuildWorldMatrix();
   glm::mat3 BuildLocalWorldMatrix();
};

