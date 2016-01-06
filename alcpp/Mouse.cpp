#include "Mouse.hpp"
#include "EventSource.hpp"

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

int Mouse::GetPrecision()
{
    return al_get_mouse_wheel_precision();
}

void Mouse::SetPrecision(int precision)
{
    al_set_mouse_wheel_precision(precision);
}

void Mouse::Poll()
{
    al_get_mouse_state(&Get());
}

bool Mouse::IsButtonDown(int button)
{
    return al_mouse_button_down(&Get(), button);
}

int Mouse::GetX() const
{
    return Get().x;
}

int Mouse::GetY() const
{
    return Get().y;
}

int Mouse::GetZ() const
{
    return Get().z;
}

int Mouse::GetW() const
{
    return Get().w;
}

}