// COS30008 - Particle Simulation

#define _USE_MATH_DEFINES
#include <cmath>
#include <numbers>
#include "Vector2D.h"

// Pi defined at file scope (not inside main)
#if defined(_HAS_CXX20) && _HAS_CXX20
static constexpr float Pi = std::numbers::pi_v<float>;
#elif __cplusplus >= 202002L
static constexpr float Pi = std::numbers::pi_v<float>;
#else
static const float Pi = static_cast<float>(M_PI);
#endif

float Vector2D::getX() const
{
    return fX;
}

float Vector2D::getY() const
{
    return fY;
}

Vector2D Vector2D::operator+(const Vector2D& aVector) const
{
    return Vector2D(fX + aVector.fX, fY + aVector.fY);
}

Vector2D Vector2D::operator-(const Vector2D& aVector) const
{
    return Vector2D(fX - aVector.fX, fY - aVector.fY);
}

Vector2D Vector2D::operator*(const float aScalar) const
{
    return Vector2D(fX * aScalar, fY * aScalar);
}

float Vector2D::dot(const Vector2D& aVector) const
{
    return fX * aVector.fX + fY * aVector.fY;
}

float Vector2D::cross(const Vector2D& aVector) const
{
    return fX * aVector.fY - fY * aVector.fX;
}

float Vector2D::length() const
{
    float val = sqrt(fX * fX + fY * fY);
    return round(val * 100.0f) / 100.0f;
}

Vector2D Vector2D::normalize() const
{
    return *this * (1.0f / length());
}

float Vector2D::direction() const
{
    float val = atan2(fY, fX) * 180.0f / Pi;
    return round(val * 100.0f) / 100.0f;
}

Vector2D Vector2D::align(float aAngleInDegrees) const
{
    float lRadians = aAngleInDegrees * Pi / 180.0f;
    return length() * Vector2D(cos(lRadians), sin(lRadians));
}

std::istream& operator>>(std::istream& aIStream, Vector2D& aVector)
{
    return aIStream >> aVector.fX >> aVector.fY;
}               

std::ostream& operator<<(std::ostream& aOStream, const Vector2D& aVector)
{
    return aOStream << "[" << round(aVector.fX) << "," << round(aVector.fY) << "]";
}

Vector2D operator*(const float aScalar, const Vector2D& aVector)
{
    return aVector * aScalar;
}