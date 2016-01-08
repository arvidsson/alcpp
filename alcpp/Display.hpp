#pragma once

#include "SharedPtr.hpp"
#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class EventSource;
class Color;

class Display : public SharedPtr<ALLEGRO_DISPLAY>
{
public:
    Display() {}
    Display(int width, int height, bool fullscreen = false);
    Display(ALLEGRO_DISPLAY *display, bool managed = true);

    int GetWidth() const;
    int GetHeight() const;

    void SetTitle(const std::string &title);

    EventSource GetEventSource() const;

    void SetAsTarget();
    void Clear(const Color& color);
    void Flip();

    bool HideMouse();
    bool ShowMouse();
    bool GrabMouse();
    bool UngrabMouse();

    enum Orientation
    {
        ZeroDegrees = ALLEGRO_DISPLAY_ORIENTATION_0_DEGREES,
        NinetyDegrees = ALLEGRO_DISPLAY_ORIENTATION_90_DEGREES,
        OneHundredEightyDegrees = ALLEGRO_DISPLAY_ORIENTATION_180_DEGREES,
        TwoHundredSeventyDegrees = ALLEGRO_DISPLAY_ORIENTATION_270_DEGREES,
        FaceUp = ALLEGRO_DISPLAY_ORIENTATION_FACE_UP,
        FaceDown = ALLEGRO_DISPLAY_ORIENTATION_FACE_DOWN
    };

    // TODO: custom mouse cursor from Bitmap
    // TODO: set system mouse cursor
    // TODO: set mouse xy
};

}