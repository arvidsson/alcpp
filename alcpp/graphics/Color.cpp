#include "Color.hpp"
#include <allegro5/allegro_color.h>
#include <algorithm>

#undef max
#undef min

namespace alcpp
{

Color::Color(float red, float green, float blue, float alpha) :
    r(red), g(green), b(blue), a(alpha) {}

Color::Color(int red, int green, int blue, int alpha) :
    r(red / 255.0f), g(green / 255.0f), b(blue / 255.0f), a(alpha / 255.0f) {}

Color::Color(const std::initializer_list<float> &components)
{
    operator=(components);
}

Color::Color(const std::initializer_list<int> &components)
{
    operator=(components);
}

Color::Color(const ALLEGRO_COLOR &color)
{
    operator=(color);
}

Color::Color(const Color &color)
{
    operator=(color);
}

Color& Color::operator=(const std::initializer_list<float> &components)
{
    std::initializer_list<float>::const_iterator it = components.begin();

    auto LimitFloat = [](float x) -> float {
        return std::max(0.0f, std::min(x, 1.0f));
    };

    if (components.size() < 4) {
        a = 1.0f;
    }

    switch (components.size()) {
        case 4: a = LimitFloat(*(it + 3));
        case 3: b = LimitFloat(*(it + 2));
        case 2: g = LimitFloat(*(it + 1));
        case 1: r = LimitFloat(*it);
    }

    return *this;
}

Color& Color::operator=(const std::initializer_list<int> &components)
{
    std::initializer_list<int>::const_iterator it = components.begin();

    auto IntToFloat = [](int x) -> float {
        x = std::max(0, std::min(x, 255));
        return x / 255.0f;
    };

    if (components.size() < 4) {
        a = 1.0f;
    }

    switch (components.size()) {
        case 4: a = IntToFloat(*(it + 3));
        case 3: b = IntToFloat(*(it + 2));
        case 2: g = IntToFloat(*(it + 1));
        case 1: r = IntToFloat(*it);
    }

    return *this;
}
    
Color& Color::operator=(const ALLEGRO_COLOR &color)
{
    al_unmap_rgba_f(color, &r, &g, &b, &a);
    return *this;
}

Color& Color::operator=(const Color &color)
{
    if (this != &color) {
        r = color.r;
        g = color.g;
        b = color.b;
        a = color.a;
    }
    return *this;
}

ALLEGRO_COLOR Color::ToAllegroColor() const
{
    return al_map_rgba_f(r, g, b, a);
}

ALLEGRO_COLOR Color::ToPremultipliedAllegroColor() const
{
    return al_premul_rgba_f(r, g, b, a);
}

float Color::GetRed() const
{
    return r;
}

float Color::GetGreen() const
{
    return g;
}

float Color::GetBlue() const
{
    return b;
}

float Color::GetAlpha() const
{
    return a;
}

void Color::SetRed(float r)
{
    this->r = r;
}

void Color::SetGreen(float g)
{
    this->r = r;
}

void Color::SetBlue(float b)
{
    this->r = r;
}

void Color::SetAlpha(float a)
{
    this->r = r;
}

void Color::Set(float r, float g, float b, float a)
{
    SetRed(r);
    SetGreen(g);
    SetBlue(b);
    SetAlpha(a);
}

void Color::ConvertFromCMYK(float cyan, float magenta, float yellow, float key)
{
    al_color_cmyk_to_rgb(cyan, magenta, yellow, key, &r, &g, &b);
}

void Color::ConvertFromHSL(float hue, float saturation, float lightness)
{
    al_color_hsl_to_rgb(hue, saturation, lightness, &r, &g, &b);
}

void Color::ConvertFromHSV(float hue, float saturation, float value)
{
    al_color_hsv_to_rgb(hue, saturation, value, &r, &g, &b);
}

bool Color::ConvertFromHTML(std::string html)
{
    return al_color_html_to_rgb(html.c_str(), &r, &g, &b);
}

bool Color::ConvertFromName(std::string colorName)
{
    return al_color_name_to_rgb(colorName.c_str(), &r, &g, &b);
}

void Color::ConvertFromYUV(float y, float u, float v)
{
    al_color_yuv_to_rgb(y, u, v, &r, &g, &b);
}

}