#include "CTransform.h"

CTransform::CTransform()
{
   m_localPosition = glm::vec2(0.0f, 0.0f);
   m_localRotation = 0.0f;
   m_localScale = glm::vec2(1.0f, 1.0f);

   m_localWorld = BuildLocalWorldMatrix();
}

CTransform::CTransform(const CTransform &other)
{
   m_localPosition = other.GetLocalPosition();
   m_localRotation = other.GetLocalRotation();
   m_localScale = other.GetLocalScale();

   m_localWorld = BuildLocalWorldMatrix();
}

CTransform::CTransform(glm::vec2 position)
{
   m_localPosition = position;
   m_localRotation = 0.0f;
   m_localScale = vec2::one;

   m_localWorld = BuildLocalWorldMatrix();
}

CTransform::CTransform(glm::vec2 position, float rotation)
{
   m_localPosition = position;
   m_localRotation = rotation;
   m_localScale = vec2::one;

   m_localWorld = BuildLocalWorldMatrix();
}

CTransform::CTransform(glm::vec2 position, float rotation, glm::vec2 scale)
{
   m_localPosition = position;
   m_localRotation = rotation;
   m_localScale = scale;

   m_localWorld = BuildLocalWorldMatrix();
}

CTransform::~CTransform()
{

}

//CTransformWeakPtr CTransform::GetParent() const
//{
//   return m_parent;
//}
//
//bool CTransform::SetParent(shared_ptr<CTransform> parent)
//{
//   m_parent = parent;
//   BuildWorldMatrix();
//}

glm::vec2 CTransform::GetLocalPosition() const { return m_localPosition; }
glm::vec2 CTransform::GetLocalScale() const { return m_localScale; }
float CTransform::GetLocalRotation() const { return m_localRotation; }
glm::mat3 CTransform::GetLocalWorldMatrix() const { return m_localWorld; }

void CTransform::Move(glm::vec2 velocity)
{
   this->SetLocalPosition(m_localPosition + velocity);
}

void CTransform::Rotate(float angVelocity)
{
   this->SetLocalRotation(m_localRotation + angVelocity);
}

void CTransform::Stretch(float sclVelocity)
{
   this->SetLocalScale(m_localScale + sclVelocity);
}

void CTransform::SetLocalPosition(glm::vec2 position)
{
   m_localPosition = position;
   m_localWorld = BuildLocalWorldMatrix();
}

void CTransform::SetLocalRotation(float rotation)
{
   m_localRotation = rotation;
   m_localWorld = BuildLocalWorldMatrix();
}

void CTransform::SetLocalScale(glm::vec2 scale)
{
   m_localScale = scale;
   m_localWorld = BuildLocalWorldMatrix();
}

//dont use this yet
glm::mat3 CTransform::BuildWorldMatrix()
{
   return mat3::identity;
}

glm::mat3x3 CTransform::BuildLocalWorldMatrix()
{
   glm::mat3 transMatrix = glm::mat3(glm::translate(mat4::identity, glm::vec3(m_localPosition, 1.0f)));
   glm::mat3 rotMatrix = glm::mat3(glm::rotate(mat4::identity, m_localRotation, vec3::forward));
   glm::mat3 scaleMatrix = glm::mat3(glm::scale(mat4::identity, glm::vec3(m_localScale, 1.0f)));

   return scaleMatrix * rotMatrix * transMatrix;
}

