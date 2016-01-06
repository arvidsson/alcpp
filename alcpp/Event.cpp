#include "Event.hpp"
#include "EventSource.hpp"

namespace alcpp
{

bool Event::IsValid() const
{
    return valid;
}

Event::operator bool() const
{
    return IsValid();
}

Event::Type Event::GetType() const
{
    return (Type)Get().type;
}

EventSource Event::GetEventSource() const
{
    return EventSource(Get().any.source);
}

double Event::GetTimestamp() const
{
    return Get().any.timestamp;
}

int Event::GetKeyboardKeycode() const
{
    return Get().keyboard.keycode;
}

int Event::GetKeyboardCharacter() const
{
    return Get().keyboard.unichar;
}

int Event::GetKeyboardModifiers() const
{
    return Get().keyboard.modifiers;
}

bool Event::GetKeyboardRepeat() const
{
    return Get().keyboard.repeat;
}

int Event::GetMouseX() const
{
    return Get().mouse.x;
}

int Event::GetMouseY() const
{
    return Get().mouse.y;
}

int Event::GetMouseZ() const
{
    return Get().mouse.z;
}

int Event::GetMouseW() const
{
    return Get().mouse.w;
}

int Event::GetMouseDX() const
{
    return Get().mouse.dx;
}

int Event::GetMouseDY() const
{
    return Get().mouse.dy;
}

int Event::GetMouseDZ() const
{
    return Get().mouse.dz;
}

int Event::GetMouseDW() const
{
    return Get().mouse.dw;
}

int Event::GetMouseButton() const
{
    return Get().mouse.button;
}

float Event::GetMousePressure() const
{
    return Get().mouse.pressure;
}

}
