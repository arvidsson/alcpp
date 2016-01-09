#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>

// because of vs :(
#undef max
#undef min

namespace alcpp
{

template <typename T>
class MathHelper
{
public:
    static const T AlmostZero;
    static const T Pi;
    static const T TwoPi;
    static const T PiOverTwo;
    static const T PiOverFour;
    static const T DegToRad;
    static const T RadToDeg;
    static const T E;

    static T ToRadians(const T degrees)
    {
        return degrees * DegToRad;
    }

    static T ToDegrees(const T radians)
    {
        return radians * RadToDeg;
    }

    static T Round(const T value)
    {
        return value > 0.0 ? std::floor(value + static_cast<T>(0.5)) : std::ceil(value - static_cast<T>(0.5));
    }

    static T Max(const T a, const T b)
    {
        return std::max(a, b);
    }

    static T Min(const T a, const T b)
    {
        return std::min(a, b);
    }

    static bool IsZero(const T value, const T epsilon = AlmostZero)
    {
        return std::abs(value) <= epsilon;
    }

    static bool IsPositive(const T value, const T epsilon = AlmostZero)
    {
        return value > epsilon;
    }

    static bool IsNegative(const T value, const T epsilon = AlmostZero)
    {
        return value < -epsilon;
    }

    static bool IsEqual(const T x1, const T x2, const T epsilon = AlmostZero)
    {
        return std::abs(x1 - x2) < epsilon;
    }

    static bool IsGreaterThan(const T x1, const T x2, const T epsilon = AlmostZero)
    {
        return x1 > (x2 + epsilon);
    }

    static bool IsLessThan(const T x1, const T x2, const T epsilon = AlmostZero)
    {
        return x1 < (x2 - epsilon);
    }

    static bool IsGreaterThanOrEqual(const T x1, const T x2, const T epsilon = AlmostZero)
    {
        return !IsLessThan(x1, x2, epsilon);
    }

    static bool IsLessThanOrEqual(const T x1, const T x2, const T epsilon = AlmostZero)
    {
        return !IsGreaterThan(x1, x2, epsilon);
    }

    static T Lerp(T a, T b, T alpha)
    {
        return a + alpha * (b - a);
    }

    static T Clamp(T x, T max, T min)
    {
        if (x > max) return max;
        if (x < min) return min;
        return x;
    }
};

template <typename T> const T MathHelper<T>::AlmostZero = static_cast<T>(0.001);
template <typename T> const T MathHelper<T>::Pi = static_cast<T>(3.141592653589793);
template <typename T> const T MathHelper<T>::TwoPi = static_cast<T>(2.0) * pi;
template <typename T> const T MathHelper<T>::PiOverTwo = pi / static_cast<T>(2.0);
template <typename T> const T MathHelper<T>::PiOverFour = pi / static_cast<T>(4.0);
template <typename T> const T MathHelper<T>::DegToRad = pi / static_cast<T>(180.0);
template <typename T> const T MathHelper<T>::RadToDeg = static_cast<T>(180.0) / pi;
template <typename T> const T MathHelper<T>::E = static_cast<T>(2.718281828459045);

}