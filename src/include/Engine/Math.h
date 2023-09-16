#pragma once

#include "Vector2.h"

class Math
{
public:
    static float Lerp(float a, float b, float t)
    {
        return a + (b - a) * t;
    }

    static float LerpAngle(float a, float b, float t)
    {
        float num = Math::Repeat(b - a, 360);
        if (num > 180)
            num -= 360;
        return a + num * Math::Clamp01(t);
    }

    static Vector2 Lerp(Vector2 a, Vector2 b, float t)
    {
        return Vector2(Lerp(a.x, b.x, t), Lerp(a.y, b.y, t));
    }

    static float Clamp(float value, float min, float max)
    {
        if (value < min)
            return min;
        if (value > max)
            return max;
        return value;
    }

    static float Clamp01(float value)
    {
        if (value < 0)
            return 0;
        if (value > 1)
            return 1;
        return value;
    }

    static float Repeat(float t, float length)
    {
        return Clamp(t - floor(t / length) * length, 0.0f, length);
    }
};