#include "Algebra.h"

#pragma region Vector2

Vector2 Vector2::ZERO = Vector2(0.0f, 0.0f);
Vector2 Vector2::ONE = Vector2(1.0f, 1.0f);
Vector2 Vector2::UNIT_X = Vector2(1.0f, 0.0f);
Vector2 Vector2::UNIT_Y = Vector2(0.0f, 1.0f);

#pragma region Constructors/Destructors
Vector2::Vector2() {
    m_data[0] = 0.0f;
    m_data[1] = 0.0f;
}

Vector2::Vector2(const Vector2 &copy) {
    m_data[0] = copy.X();
    m_data[1] = copy.Y();
}

Vector2::Vector2(float x, float y) {
    m_data[0] = x;
    m_data[1] = y;
}

Vector2::Vector2(const Vector3 &vec3) {

}

Vector2::~Vector2() {

}
#pragma endregion

#pragma region Accessors/Mutators
float Vector2::X() const {
    return m_data[0];
}

float Vector2::Y() const {
    return m_data[1];
}

void Vector2::X(float nx) {
    m_data[0] = nx;
}

void Vector2::Y(float ny) {
    m_data[1] = ny;
}
#pragma endregion

#pragma region Operator Overloads
void Vector2::operator=(const Vector2 &other) {
    this->m_data[0] = other.X();
    this->m_data[1] = other.Y();
}

void Vector2::operator+=(const Vector2 &other) {
    *this = *this + other;
}

void Vector2::operator-=(const Vector2 &other) {
    *this = *this - other;
}

void Vector2::operator*=(const Vector2 &other) {
    *this = *this * other;
}

void Vector2::operator*=(const float &scalar) {
    *this = *this * scalar;
}

void Vector2::operator/=(const Vector2 &other) {
    *this = *this / other;
}

void Vector2::operator/=(const float &scalar) {
    *this = *this / scalar;
}

Vector2 Vector2::operator-() const {
    return Vector2(-this->X(), -this->Y());
}
#pragma endregion

#pragma region Math Functions
float Vector2::Length() const {
    return sqrtf(this->LengthSqr());
}

float Vector2::LengthSqr() const {
    return (m_data[0] * m_data[0] + m_data[1] * m_data[1]);
}

void Vector2::Normalize() {
    float l = this->Length();
    m_data[0] /= l;
    m_data[1] /= l;
}

Vector2 Vector2::Normalized() const {
    float l = this->Length();
    return Vector2(this->X() / l, this->Y() / l);
}

float Vector2::Distance(const Vector2 &other) const {
    return sqrtf(DistanceSqr(other));
}

float Vector2::DistanceSqr(const Vector2 &other) const {
    return (other - *(this)).LengthSqr();
}

float Vector2::Dot(const Vector2 &other) const {
    return (this->X() * other.X() + this->Y() * other.Y());
}

float Vector2::Distance(const Vector2 &lhs, const Vector2 &rhs) {
    return lhs.Distance(rhs);
}

float Vector2::DistanceSqr(const Vector2 &lhs, const Vector2 &rhs) {
    return lhs.DistanceSqr(rhs);
}

float Vector2::Dot(const Vector2 &lhs, const Vector2 &rhs) {
    return lhs.Dot(rhs);
}
#pragma endregion

#pragma endregion

#pragma region Vector3

Vector3 Vector3::ZERO = Vector3(0.0f, 0.0f, 0.0f);
Vector3 Vector3::ONE = Vector3(1.0f, 1.0f, 1.0f);
Vector3 Vector3::RIGHT = Vector3(1.0f, 0.0f, 0.0f);
Vector3 Vector3::LEFT = Vector3(-1.0f, 0.0f, 0.0f);
Vector3 Vector3::UP = Vector3(0.0f, 1.0f, 0.0f);
Vector3 Vector3::DOWN = Vector3(0.0f, -1.0f, 0.0f);
Vector3 Vector3::FORWARD = Vector3(0.0f, 0.0f, -1.0f);
Vector3 Vector3::BACKWARD = Vector3(0.0f, 0.0f, 1.0f);

#pragma region Constructors/Destructors
Vector3::Vector3() {
    m_data[0] = 0.0f;
    m_data[1] = 0.0f;
    m_data[2] = 0.0f;
}

Vector3::Vector3(const Vector3 &copy) {
    m_data[0] = copy.X();
    m_data[1] = copy.Y();
    m_data[2] = copy.Z();
}

Vector3::Vector3(float x, float y, float z) {
    m_data[0] = x;
    m_data[1] = y;
    m_data[2] = z;
}

Vector3::~Vector3() {

}
#pragma endregion

#pragma region Accessors/Mutators
float Vector3::X() const {
    return m_data[0];
}

float Vector3::Y() const {
    return m_data[1];
}

float Vector3::Z() const {
    return m_data[2];
}

void Vector3::X(float nx) {
    m_data[0] = nx;
}

void Vector3::Y(float ny) {
    m_data[1] = ny;
}

void Vector3::Z(float nz) {
    m_data[2] = nz;
}
#pragma endregion

#pragma region Operator Overloads
void Vector3::operator=(const Vector3 &other) {
    this->m_data[0] = other.X();
    this->m_data[1] = other.Y();
    this->m_data[2] = other.Z();
}

void Vector3::operator+=(const Vector3 &other) {
    *this = *this + other;
}

void Vector3::operator-=(const Vector3 &other) {
    *this = *this - other;
}

void Vector3::operator*=(const Vector3 &other) {
    *this = *this * other;
}

void Vector3::operator*=(const float &scalar) {
    *this = *this * scalar;
}

void Vector3::operator/=(const Vector3 &other) {
    *this = *this / other;
}

void Vector3::operator/=(const float &scalar) {
    *this = *this / scalar;
}

Vector3 Vector3::operator-() const {
    return Vector3(-this->X(), -this->Y(), -this->Z());
}
#pragma endregion

#pragma region Math Functions
float Vector3::Length() const {
    return sqrtf(this->LengthSqr());
}

float Vector3::LengthSqr() const {
    return (m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2]);
}

void Vector3::Normalize() {
    float l = this->Length();
    m_data[0] /= l;
    m_data[1] /= l;
    m_data[2] /= l;
}

Vector3 Vector3::Normalized() const {
    float l = this->Length();
    return Vector3(this->X() / l, this->Y() / l, this->Z() / l);
}
#pragma endregion

#pragma endregion