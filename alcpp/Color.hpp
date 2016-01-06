#pragma once

#include <allegro5/allegro.h>
#include <initializer_list>
#include <string>

namespace alcpp
{

class Color
{
public:
    // Constructors.
    Color(float red = 0.0f, float green = 0.0f, float blue = 0.0f, float alpha = 1.0f);
    Color(int red, int green, int blue, int alpha = 255);
    Color(const std::initializer_list<float> &components);
    Color(const std::initializer_list<int> &components);
    Color(const ALLEGRO_COLOR &color);
    Color(const Color &color);

    // Assignment operators.
    Color& operator=(const std::initializer_list<float> &components);
    Color& operator=(const std::initializer_list<int> &components);
    Color& operator=(const ALLEGRO_COLOR &color);
    Color& operator=(const Color &color);

    // Transforms (r,g,b,a) to the allegro color struct and returns it.
    ALLEGRO_COLOR ToAllegroColor() const;

    float GetRed() const;
    float GetGreen() const;
    float GetBlue() const;
    float GetAlpha() const;
    void SetRed(float r);
    void SetGreen(float g);
    void SetBlue(float b);
    void SetAlpha(float a);
    void Set(float r, float g, float b, float a);

    void ConvertFromCMYK(float cyan, float magenta, float yellow, float key);
    void ConvertFromHSL(float hue, float saturation, float lightness);
    void ConvertFromHSV(float hue, float saturation, float value);
    bool ConvertFromHTML(std::string html);
    bool ConvertFromName(std::string colorName);
    void ConvertFromYUV(float y, float u, float v);

private:
    float r, g, b, a;
};

}