
#pragma once
#include <cmath>

class Vector2
{
public:
    constexpr static float PI_F = 3.14159265358979f;
    constexpr static float GRADUS = PI_F / 180.0f;
    constexpr static float RADIAN = 180.0f / PI_F;

    const static Vector2 ZERO;
    const static Vector2 UP;
    const static Vector2 DOWN;
    const static Vector2 LEFT;
    const static Vector2 RIGHT;

    Vector2();
    Vector2(const float &x, const float &y);

    float x, y;

    float Magnitude() const;
    float LengthSqr() const;
    float Dot(const Vector2 &right) const;
    float GetAngle() const;
    Vector2 Normalized() const;
    Vector2 GetRotated(const float &angle) const;

    bool EqualTo(const Vector2 &right) const;

    void Rotate(const float &angle);

    Vector2 &operator=(const Vector2 &right);
    bool operator==(const Vector2 &right) const;

    friend const Vector2 operator+(const Vector2 &left, const Vector2 &right);
    friend const Vector2 operator-(const Vector2 &left, const Vector2 &right);
    friend const Vector2 operator*(const Vector2 &left, const Vector2 &right);
    friend const Vector2 operator*(const Vector2 &left, const float &scale);
    friend const Vector2 operator/(const Vector2 &left, const Vector2 &right);
    friend const Vector2 operator/(const Vector2 &left, const float &scale);

    Vector2 &operator+=(const Vector2 &right);
    Vector2 &operator-=(const Vector2 &right);
    Vector2 &operator*=(const Vector2 &right);
    Vector2 &operator*=(const float &scale);

private:
    mutable bool _changed_length = true;
    mutable bool _changed_angle = true;

    mutable float _cache_length = false;
    mutable float _cache_angle = false;

    void SetCacheFlagTrue();
};

inline Vector2::Vector2() : x(0.0f), y(0.0f)
{
}

inline Vector2::Vector2(const float &x, const float &y) : x(x), y(y)
{
}

inline float Vector2::Magnitude() const
{
    if (_changed_length)
    {
        _cache_length = sqrt(x * x + y * y);
        _changed_length ^= 1; // fast bool invert
    }
    return _cache_length;
}

inline float Vector2::LengthSqr() const
{
    return (x * x + y * y);
}

inline float Vector2::Dot(const Vector2 &right) const
{
    return (this->x * right.x) + (this->y * right.y);
}

inline float Vector2::GetAngle() const
{
    if (_changed_angle)
    {
        _cache_angle = atan2(this->y, this->x) * RADIAN;
        _changed_angle ^= 1; // fast bool invert
    }
    return _cache_angle;
}

inline Vector2 Vector2::Normalized() const
{
    float len = this->Magnitude();
    return Vector2(this->x / len, this->y / len);
}

inline Vector2 Vector2::GetRotated(const float &angle) const
{
    float rad = angle * GRADUS;
    float sn = sin(rad);
    float cs = cos(rad);

    return Vector2((x * cs - y * sn), (x * sn + y * cs));
}

inline bool Vector2::EqualTo(const Vector2 &right) const
{
    return *this == right;
}

inline void Vector2::Rotate(const float &angle)
{
    float rad = angle * GRADUS;
    float sn = sin(rad);
    float cs = cos(rad);

    this->x = (x * cs - y * sn);
    this->y = (x * sn + y * cs);
}

inline Vector2 &Vector2::operator=(const Vector2 &right)
{
    if (this != &right)
    {
        this->x = right.x;
        this->y = right.y;
        SetCacheFlagTrue();
    }
    return *this;
}

inline bool Vector2::operator==(const Vector2 &right) const
{
    return (this->x == right.x) && (this->y == right.y);
}

inline void Vector2::SetCacheFlagTrue()
{
    _changed_length = true;
    _changed_angle = true;
}

inline const Vector2 operator+(const Vector2 &left, const Vector2 &right)
{
    return Vector2(left.x + right.x, left.y + right.y);
}

inline const Vector2 operator-(const Vector2 &left, const Vector2 &right)
{
    return Vector2(left.x - right.x, left.y - right.y);
}

inline const Vector2 operator*(const Vector2 &left, const Vector2 &right)
{
    return Vector2(left.x * right.x, left.y * right.y);
}

inline const Vector2 operator*(const Vector2 &left, const float &scale)
{
    return Vector2(left.x * scale, left.y * scale);
}

inline const Vector2 operator/(const Vector2 &left, const Vector2 &right)
{
    return Vector2(left.x / right.x, left.y / right.y);
}

inline const Vector2 operator/(const Vector2 &left, const float &scale)
{
    return Vector2(left.x / scale, left.y / scale);
}

inline Vector2 &Vector2::operator+=(const Vector2 &right)
{
    this->x += right.x;
    this->y += right.y;
    this->SetCacheFlagTrue();
    return *this;
}

inline Vector2 &Vector2::operator-=(const Vector2 &right)
{
    this->x -= right.x;
    this->y -= right.y;
    this->SetCacheFlagTrue();
    return *this;
}

inline Vector2 &Vector2::operator*=(const Vector2 &right)
{
    this->x *= right.x;
    this->y *= right.y;
    this->SetCacheFlagTrue();
    return *this;
}

inline Vector2 &Vector2::operator*=(const float &scale)
{
    this->x *= scale;
    this->y *= scale;
    this->SetCacheFlagTrue();
    return *this;
}