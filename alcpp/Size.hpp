#pragma once

#include "MathHelper.hpp"
#include <initializer_list>
#include <string>
#include <sstream>

namespace alcpp
{

template <typename T>
class Size
{
public:
    Size(T w = 0, T h = 0) : w(w), h(h) {}
    Size(const Size<T> &size) = default;
    Size<T>& operator=(const Size<T> &size) = default;

    Size<T>& operator=(const std::initializer_list<T> &dimensions)
    {
        typename std::initializer_list<T>::const_iterator it = dimensions.begin();
        switch (dimensions.size()) {
        case 2: h = *(it + 1);
        case 1: w = *it;
        }
        return *this;
    }

    T GetWidth() const
    {
        return w;
    }

    T GetHeight() const
    {
        return h;
    }

    T GetArea() const
    {
        return w * h;
    }

    bool operator<(const Size<T> &size) const
    {
        return area() < size.area();
    }

    bool operator<=(const Size<T> &size) const
    {
        return area() <= size.area();
    }

    bool operator>(const Size<T> &size) const
    {
        return area() > size.area();
    }

    bool operator>=(const Size<T> &size) const
    {
        return area() >= size.area();
    }

    std::string ToString() const
    {
        std::stringstream ss;
        ss << "(" << GetWidth() << "," << GetHeight() << ")";
        return ss.str();
    }

    T w, h;
};

template <class T> Size<T> MakeSize(T w, T h)
{
    return Size<T>(w, h);
}

}