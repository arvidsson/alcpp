#pragma once

#include "ValueWrapper.hpp"
#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class EventSource;

class MouseButton
{
public:
    enum
    {
        Left = 1,
        Right,
        Middle,
        Max
    };
};

class Mouse : public ValueWrapper<ALLEGRO_MOUSE_STATE>
{
public:
    static bool Install();
    static void Uninstall();
    static bool IsInstalled();

    static EventSource GetEventSource();
    static int GetNumAxes();
    static int GetNumButtons();

    static bool SetZ(int z);
    static bool SetW(int w);
    static int GetPrecision();
    static void SetPrecision(int precision);

    void Poll();
    bool IsButtonDown(int button);
    int GetX() const;
    int GetY() const;
    int GetZ() const;
    int GetW() const;
};

}