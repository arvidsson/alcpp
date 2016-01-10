#pragma once

#include "MathHelper.hpp"
#include <initializer_list>
#include <vector>
#include <string>
#include <sstream>

namespace alcpp
{

template <typename T> class Vec2
{
public:
    Vec2(T x = 0, T y = 0) : x(x), y(y) {}
    Vec2(const Vec2<T> &v) = default;
    Vec2<T>& operator=(const Vec2<T> &v) = default;

    Vec2<T>& operator=(const std::initializer_list<T> &coords)
    {
        typename std::initializer_list<T>::const_iterator it = coords.begin();
        switch (coords.size()) {
        case 2: y = *(it + 1);
        case 1: x = *it;
        }
        return *this;
    }

    Vec2(const std::vector<T> &v)
    {
        x = v[0];
        y = v[1];
    }

    Vec2<T>& operator=(const std::vector<T> &v)
    {
        x = v[0];
        y = v[1];
        return *this;
    }

    bool operator==(const Vec2<T> &v) const
    {
        return x == v.x && y = v.y;
    }

    bool IsEqual(const Vec2<T> &v, const T epsilon = MathHelper<T>::AlmostZero) const
    {
        return MathHelper<T>::IsEqual(x, v.x, epsilon) && MathHelper<T>::IsEqual(y, v.y, epsilon);
    }

    bool operator!=(const Vec2<T> &v) const
    {
        return !(operator==(v));
    }

    friend Vec2<T> operator+(const Vec2<T> &v1, const Vec2<T> &v2)
    {
        return Vector<T>(v1.x + v2.x, v1.y + v2.y);
    }

    Vec2<T>& operator+=(const Vec2<T> &v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    friend Vec2<T> operator-(const Vec2<T> &v1, const Vec2<T> &v2)
    {
        return Vec2<T>(v1.x - v2.x, v1.y - v2.y);
    }

    Vec2<T> operator-() const
    {
        return Vec2<T>(-x, -y);
    }

    Vec2<T>& operator-=(const Vec2<T> &v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vec2<T> operator*(T f) const
    {
        return Vec2<T>(x * f, y * f);
    }

    Vec2<T>& operator*=(T f)
    {
        x *= f;
        y *= f;
        return *this;
    }

    Vec2<T> operator/(T f) const
    {
        return Vec2<T>(x / f, y / f);
    }

    Vec2<T>& operator/=(T f)
    {
        x /= f;
        y /= f;
        return *this;
    }

    T GetX() const { return x; }
    T GetY() const { return y; }

    T GetDotProduct(const Vec2<T> &v) const
    {
        return x * v.x + y * v.y;
    }

    T GetCrossProduct(const Vec2<T> &v) const
    {
        return x * v.y - y * v.x;
    }

    T GetLength() const
    {
        return std::sqrt(x * x + y * y);
    }

    T GetLengthSquared() const
    {
        return x * x + y * y;
    }

    void Normalize()
    {
        T l = GetLength();
        if (l) {
            x /= l;
            y /= l;
        }
    }

    Vec2<T> GetNormalized() const
    {
        T l = GetLength();
        return l ? Vec2<T>(x / l, y / l) : Vec2<T>();
    }

    Vec2<T> GetPolar(T angle, T length) const
    {
        return Vec2<T>(length * std::cos(angle), length * std::sin(angle));
    }

    T GetMagnitude() const
    {
        return GetLength();
    }

    T GetDirection() const
    {
        return std::atan2(y, x);
    }

    T GetAngle() const
    {
        return GetDirection();
    }

    T DistanceTo(const Vec2<T> &v)
    {
        T dx = v.x - x;
        T dy = v.y - y;
        return std::sqrt(dx * dx + dy * dy);
    }

    Vec2<T> Lerp(const Vec2<T> &v, T alpha)
    {
        Vec2<T> t;
        t.x = MathHelper<T>::Lerp(x, v.x, alpha);
        t.y = MathHelper<T>::Lerp(y, v.y, alpha);
        return t;
    }

    std::string ToString() const
    {
        std::stringstream ss;
        ss << "(" << GetX() << "," << GetY() << ")";
        return ss.str();
    }

    T x, y;
};

template <class T> Vec2<T> MakeVector(T x, T y)
{
    return Vec2<T>(x, y);
}

using int2 = Vec2<int>;
using float2 = Vec2<float>;
using double2 = Vec2<double>;

using Vec2i = Vec2<int>;
using Vec2ui = Vec2<unsigned int>;
using Vec2f = Vec2<float>;
using Vec2d = Vec2<double>;

}