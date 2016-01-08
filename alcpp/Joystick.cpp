#include "Joystick.hpp"
#include "EventSource.hpp"

namespace alcpp
{

Joystick::Joystick(int num) : SharedPtr(al_get_joystick(num), al_release_joystick) {}

bool Joystick::IsActive() const
{
    return al_get_joystick_active(get());
}

std::string Joystick::GetName() const
{
    return al_get_joystick_name(get());
}

std::string Joystick::GetStickName(int stick) const
{
    return al_get_joystick_stick_name(get(), stick);
}

std::string Joystick::GetAxisName(int stick, int axis) const
{
    return al_get_joystick_axis_name(get(), stick, axis);
}

std::string Joystick::GetButtonName(int button) const
{
    return al_get_joystick_button_name(get(), button);
}

int Joystick::GetNumSticks() const
{
    return al_get_joystick_num_sticks(get());
}

int Joystick::GetNumAxes(int stick) const
{
    return al_get_joystick_num_axes(get(), stick);
}

int Joystick::GetNumButtons() const
{
    return al_get_joystick_num_buttons(get());
}

bool Joystick::Install()
{
    return al_install_joystick();
}

void Joystick::Uninstall()
{
    al_uninstall_joystick();
}

bool Joystick::IsInstalled()
{
    return al_is_joystick_installed();
}

EventSource Joystick::GetEventSource()
{
    return EventSource(al_get_joystick_event_source());
}

void Joystick::Reconfigure()
{
    al_reconfigure_joysticks();
}

int Joystick::GetNumJoysticks()
{
    return al_get_num_joysticks();
}

}