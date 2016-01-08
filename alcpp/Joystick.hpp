#pragma once

#include "SharedPtr.hpp"
#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class EventSource;

class Joystick : public SharedPtr<ALLEGRO_JOYSTICK>
{
public:
    Joystick(int num);

    bool IsActive() const;

    std::string GetName() const;
    std::string GetStickName(int stick) const;
    std::string GetAxisName(int stick, int axis) const;
    std::string GetButtonName(int button) const;

    int GetNumSticks() const;
    int GetNumAxes(int stick) const;
    int GetNumButtons() const;

    static bool Install();
    static void Uninstall();
    static bool IsInstalled();

    static EventSource GetEventSource();
    static void Reconfigure();
    static int GetNumJoysticks();
};

}