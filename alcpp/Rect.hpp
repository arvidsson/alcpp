#pragma once

#include "Vec2.hpp"
#include "Size.hpp"
#include "MathHelper.hpp"
#include <initializer_list>
#include <string>
#include <sstream>

namespace alcpp
{

template <class T> class Rect
{
public:
    Rect(T x = 0, T y = 0, T w = 0, T h = 0) : position(x, y), size(w, h) {}
    Rect(const Vec2<T> &position, const Size<T> &size) : position(position), size(size) {}
    Rect(const Rect<T> &rect) = default;
    Rect<T>& operator=(const Rect<T> &rect) = default;

    Rect(const Vec2<T> &topLeft, const Vec2<T> &bottomRight)
    {
        position = topLeft;
        size = { bottomRight.x - topLeft.x, bottomRight.y - topLeft.y };
    }

    // {x, y, w, h}
    Rect<T>& operator=(const std::initializer_list<T> &coords)
    {
        typename std::initializer_list<T>::const_iterator it = coords.begin();
        switch (coords.size()) {
        case 4: size.h = *(it + 3);
        case 3: size.w = *(it + 2);
        case 2: position.y = *(it + 1);
        case 1: position.x = *it;
        }

        if (coords.size() > 3) {
            size.h = position.y + sizeh;
        }
        else {
            size.h = 0;
        }

        if (coords.size() > 2) {
            size.w = position.x + size.w;
        }
        else {
            size.w = 0;
        }

        return *this;
    }

    T GetX() const
    {
        return position.x;
    }

    T GetY() const
    {
        return position.y;
    }

    Vec2<T> GetPosition() const
    {
        return position;
    }

    T GetWidth() const
    {
        return size.w;
    }

    T GetHeight() const
    {
        return size.h;
    }

    Size<T> GetSize() const
    {
        return size;
    }

    T GetArea() const
    {
        return size.GetArea();
    }

    T Left() const
    {
        return position.x;
    }

    T Right() const
    {
        return position.x + size.w;
    }

    T Top() const
    {
        return position.y;
    }

    T Bottom() const
    {
        return position.y + size.h;
    }

    Vec2<T> TopLeft() const
    {
        return Vec2<T>(Left(), Top());
    }

    Vec2<T> BottomRight() const
    {
        return Vec2<T>(Right(), Bottom());
    }

    T GetCenterX() const
    {
        return position.x + (size.w / 2);
    }

    T GetCenterY() const
    {
        return position.y + (size.h / 2);
    }

    Vec2<T> GetCenter() const
    {
        return Vec2<T>(GetCenterX(), GetCenterY());
    }

    void MoveTo(T x, T y)
    {
        position = { x, y };
    }

    void MoveBy(T dx, T dy)
    {
        position.x += dx;
        position.y += dy;
    }

    void SetSize(T w, T h)
    {
        size = { w, h };
    }

    void GrowBy(T dw, T dh)
    {
        size.w += dw;
        size.h += dh;
    }

    void ShrinkBy(T dw, T dh)
    {
        size.w -= dw;
        size.h -= dh;
    }

    // Returns true if the rectangle contains a point.
    bool Contains(T x, T y) const
    {
        return !(x < Left() || x > Right() || y < Top() || y > Bottom());
    }

    // Returns true if the rectangle contains a point.
    bool Contains(const Vec2<T> &point) const
    {
        return Contains(point.x, point.y);
    }

    // Returns true if the rectangle contains another rectangle.
    bool Contains(const Rect<T> &rect) const
    {
        return Contains(rect.TopLeft()) && Contains(rect.BottomRight());
    }

    // Returns true if the rectangle intersects another rectangle.
    bool Intersects(T l, T t, T r, T b) const
    {
        return !(l > Right() || r < Left() || t > Bottom() || b < Top());
    }

    // Returns true if the rectangle intersects another rectangle.
    bool Intersects(const Rect<T> &rect) const
    {
        return Intersects(rect.Left(), rect.Top(), rect.Right(), rect.Bottom());
    }

    // Return a string representation of the rectangle (position and size).
    std::string ToString() const
    {
        std::stringstream ss;
        ss << "((" << Left() << "," + Top() << "),(" << GetWidth() << "x" << GetHeight() << "))";
        return ss.str();
    }

    Vec2<T> position;
    Size<T> size;
};

template <class T> Rect<T> MakeRect(T x, T y, T w, T h)
{
    return Rect<T>(x, y, w, h);
}

template <class T> Rect<T> MakeRect(const Vec2<T> &position, const Size<T> &size)
{
    return Rect<T>(position, size);
}

}