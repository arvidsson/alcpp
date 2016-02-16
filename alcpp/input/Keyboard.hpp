#pragma once

#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class EventSource;

class Keyboard
{
public:
    /*
        Installs keyboard driver.
    */
    static bool Install();

    /*
        Uninstalls keyboard driver.
    */
    static void Uninstall();

    /*
        Returns true if keyboard driver is installed.
    */
    static bool IsInstalled();

    /*
        Returns the keyboard event source.
    */
    static EventSource GetEventSource();

    /*
        Returns name for the given key.
    */
    static std::string GetKeycodeName(int keycode);
};

}