#pragma once

#include "ValueWrapper.hpp"
#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class EventSource;

class Keyboard : public ValueWrapper<ALLEGRO_KEYBOARD_STATE>
{
public:
    static bool Install();
    static void Uninstall();
    static bool IsInstalled();

    static EventSource GetEventSource();
    static std::string GetKeycodeName(int keycode);

    void Poll();
    bool IsKeyDown(int keycode);
};

}