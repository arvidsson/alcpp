#pragma once

#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class EventSource;

class Mouse
{
public:
    /*
        Installs mouse driver.
    */
    static bool Install();

    /*
        Uninstalls mouse driver.
    */
    static void Uninstall();

    /*
        Returns true if mouse driver is installed.
    */
    static bool IsInstalled();

    /*
        Returns mouse event source.
    */
    static EventSource GetEventSource();

    /*
        Returns the number of axes on the mouse. 
    */
    static int GetNumAxes();

    /*
        Returns the number of buttons on the mouse.
    */
    static int GetNumButtons();

    /*
        Set first and second mouse wheel position.
    */
    static bool SetZ(int z);
    static bool SetW(int w);

    /*
        Getter and setter for mouse wheel precision.
    */
    static int GetWheelPrecision();
    static void SetWheelPrecision(int precision);
};

}