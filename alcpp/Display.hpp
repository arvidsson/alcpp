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

    // TODO: custom mouse cursor from Bitmap
    // TODO: set system mouse cursor
    // TODO: set mouse xy
};

}