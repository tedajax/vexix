#pragma once

#include <array>
#include <cmath>
#include <cstdint>

const float EPSILON = 1.19209290E-07F;

class Vector2;
class Vector3;
class Matrix3;

class Vector2
{
public:
   Vector2();
   Vector2(const Vector2 &copy);
   Vector2(float x, float y);
   Vector2(const Vector3 &vec3);

   ~Vector2();

   float    X() const;
   float    Y() const;
   void     X(float nx);
   void     Y(float ny);

   void     operator=(const Vector2 &other);
   void     operator+=(const Vector2 &other);
   void     operator-=(const Vector2 &other);
   void     operator*=(const Vector2 &other);
   void     operator*=(const float &scalar);
   void     operator/=(const Vector2 &other); 
   void     operator/=(const float &scalar);
   Vector2  operator-() const;

   float    Length() const;
   float    LengthSqr() const;
   void     Normalize();
   Vector2  Normalized() const;
   float    Distance(const Vector2 &other) const;
   float    DistanceSqr(const Vector2 &other) const;
   float    Dot(const Vector2 &other) const;

   static float Distance(const Vector2 &lhs, const Vector2 &rhs);
   static float DistanceSqr(const Vector2 &lhs, const Vector2 &rhs);
   static float Dot(const Vector2 &lhs, const Vector2 &rhs);

   static Vector2 ZERO;
   static Vector2 ONE;
   static Vector2 UNIT_X;
   static Vector2 UNIT_Y;
   
private:
   std::array<float, 2> m_data;
};

class Vector3
{
public:
   Vector3();
   Vector3(const Vector3 &copy);
   Vector3(float x, float y, float z);
   
   ~Vector3();

   float    X() const;
   float    Y() const;
   float    Z() const;
   void     X(float nx);
   void     Y(float ny);
   void     Z(float nz);

   void     operator=(const Vector3 &other);
   void     operator+=(const Vector3 &other);
   void     operator-=(const Vector3 &other);
   void     operator*=(const Vector3 &other);
   void     operator*=(const float &scalar);
   void     operator/=(const Vector3 &other);
   void     operator/=(const float &scalar);
   Vector3  operator-() const;

   float    Length() const;
   float    LengthSqr() const;
   void     Normalize();
   Vector3  Normalized() const;

   static Vector3 ZERO;
   static Vector3 ONE;
   static Vector3 RIGHT;
   static Vector3 LEFT;
   static Vector3 UP;
   static Vector3 DOWN;
   static Vector3 FORWARD;
   static Vector3 BACKWARD;

private:
   std::array<float, 3> m_data;
};

class Matrix3
{
public:
   Matrix3();
   Matrix3(const Matrix3 &copy);
   Matrix3(float m11, float m12, float m13,
           float m21, float m22, float m23,
           float m31, float m32, float m33);
   
   ~Matrix3();

   float    operator()(uint32_t row, uint32_t col);

private:
   std::array<float, 9> m_data;
};

#pragma region Vector2 Inline Functions
inline bool operator==(const Vector2 &lhs, const Vector2 &rhs)
{
   return ((fabs(lhs.X() - rhs.X()) <= EPSILON) && (fabs(lhs.Y() - rhs.Y()) <= EPSILON));
}

inline bool operator!=(const Vector2 &lhs, const Vector2 &rhs)
{
   return !(lhs == rhs);
}

inline Vector2 operator+(const Vector2 &lhs, const Vector2 &rhs)
{
   return Vector2(lhs.X() + rhs.X(), lhs.Y() + rhs.Y());
}

inline Vector2 operator-(const Vector2 &lhs, const Vector2 &rhs)
{
   return Vector2(lhs.X() - rhs.X(), lhs.Y() - rhs.Y());
}

inline Vector2 operator*(const Vector2 &lhs, const Vector2 &rhs)
{
   return Vector2(lhs.X() * rhs.X(), lhs.Y() * rhs.Y());
}

inline Vector2 operator*(const Vector2 &lhs, const float scalar)
{
   return Vector2(lhs.X() * scalar, lhs.Y() * scalar);
}

inline Vector2 operator*(const float scalar, const Vector2 &rhs)
{
   return Vector2(scalar * rhs.X(), scalar * rhs.Y());
}

inline Vector2 operator/(const Vector2 &lhs, const Vector2 &rhs)
{
   return Vector2(lhs.X() / rhs.X(), lhs.Y() / rhs.Y());
}

inline Vector2 operator/(const Vector2 &lhs, const float scalar)
{
   return Vector2(lhs.X() / scalar, lhs.Y() / scalar);
}

inline Vector2 operator/(const float scalar, const Vector2 &rhs)
{
   return Vector2(scalar / rhs.X(), scalar / rhs.Y());
}
#pragma endregion

#pragma region Vector3 Inline Function
inline bool operator==(const Vector3 &lhs, const Vector3 &rhs)
{
   return ((fabs(lhs.X() - rhs.X()) <= EPSILON) && 
           (fabs(lhs.Y() - rhs.Y()) <= EPSILON) &&
           (fabs(lhs.Z() - rhs.Z()) <= EPSILON));
}

inline bool operator!=(const Vector3 &lhs, const Vector3 &rhs)
{
   return !(lhs == rhs);
}

inline Vector3 operator+(const Vector3 &lhs, const Vector3 &rhs)
{
   return Vector3(lhs.X() + rhs.X(), lhs.Y() + rhs.Y(), lhs.Z() + rhs.Z());
}

inline Vector3 operator-(const Vector3 &lhs, const Vector3 &rhs)
{
   return Vector3(lhs.X() - rhs.X(), lhs.Y() - rhs.Y(), lhs.Z() - rhs.Z());
}

inline Vector3 operator*(const Vector3 &lhs, const Vector3 &rhs)
{
   return Vector3(lhs.X() * rhs.X(), lhs.Y() * rhs.Y(), lhs.Z() * rhs.Z());
}

inline Vector3 operator*(const Vector3 &lhs, const float scalar)
{
   return Vector3(lhs.X() * scalar, lhs.Y() * scalar, lhs.Z() * scalar);
}

inline Vector3 operator*(const float scalar, const Vector3 &rhs)
{
   return Vector3(scalar * rhs.X(), scalar * rhs.Y(), scalar * rhs.Z());
}

inline Vector3 operator/(const Vector3 &lhs, const Vector3 &rhs)
{
   return Vector3(lhs.X() / rhs.X(), lhs.Y() / rhs.Y(), lhs.Z() / rhs.Z());
}

inline Vector3 operator/(const Vector3 &lhs, const float scalar)
{
   return Vector3(lhs.X() / scalar, lhs.Y() / scalar, lhs.Z() / scalar);
}

inline Vector3 operator/(const float scalar, const Vector3 &rhs)
{
   return Vector3(scalar / rhs.X(), scalar / rhs.Y(), scalar / rhs.Z());
}
#pragma endregion