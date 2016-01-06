#include "Keyboard.hpp"
#include "EventSource.hpp"

namespace alcpp
{

bool Keyboard::Install()
{
    return al_install_keyboard();
}

void Keyboard::Uninstall()
{
    al_uninstall_keyboard();
}

bool Keyboard::IsInstalled()
{
    return al_is_keyboard_installed();
}

EventSource Keyboard::GetEventSource()
{
    return EventSource(al_get_keyboard_event_source());
}

std::string Keyboard::GetKeycodeName(int keycode)
{
    return al_keycode_to_name(keycode);
}

void Keyboard::Poll()
{
    al_get_keyboard_state(&Get());
}

bool Keyboard::IsKeyDown(int keycode)
{
    return al_key_down(&Get(), keycode);
}

}