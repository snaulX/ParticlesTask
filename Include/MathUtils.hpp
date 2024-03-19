#pragma once

#include "raylib.h"

static void operator+=(Vector2& lhs, const Vector2& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
}
static void operator-=(Vector2& lhs, const Vector2& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
}

static Vector2 operator*(const Vector2& lhs, float rhs)
{
    return Vector2{lhs.x * rhs, lhs.y * rhs};
}
static Vector2 operator+(const Vector2& lhs, float rhs)
{
    return Vector2{lhs.x + rhs, lhs.y + rhs};
}
static Color operator*(const Color& lhs, const Color& rhs)
{
    return ColorTint(lhs, rhs);
}

// Cross-type sign function
template<typename T, std::enable_if_t<std::is_arithmetic_v<T>, bool> = true>
inline int sign(T val)
{
    return (T(0) < val) - (val < T(0));
}