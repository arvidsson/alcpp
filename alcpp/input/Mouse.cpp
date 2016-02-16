#include "Mouse.hpp"
#include "../event/EventSource.hpp"

namespace alcpp
{

bool Mouse::Install()
{
    return al_install_mouse();
}

void Mouse::Uninstall()
{
    al_uninstall_mouse();
}

bool Mouse::IsInstalled()
{
    return al_is_mouse_installed();
}

EventSource Mouse::GetEventSource()
{
    return EventSource(al_get_mouse_event_source());
}

int Mouse::GetNumAxes()
{
    return al_get_mouse_num_axes();
}

int Mouse::GetNumButtons()
{
    return al_get_mouse_num_buttons();
}

bool Mouse::SetZ(int z)
{
    return al_set_mouse_z(z);
}

bool Mouse::SetW(int w)
{
    return al_set_mouse_w(w);;
}

int Mouse::GetWheelPrecision()
{
    return al_get_mouse_wheel_precision();
}

void Mouse::SetWheelPrecision(int precision)
{
    al_set_mouse_wheel_precision(precision);
}

}