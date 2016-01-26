#include "Event.hpp"
#include "EventSource.hpp"
#include "../graphics/Display.hpp"
#include "../time/Timer.hpp"
#include "../util/ToIntegral.hpp"

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
    return (Type)ev.type;
}

EventSource Event::GetEventSource() const
{
    return EventSource(ev.any.source);
}

double Event::GetTimestamp() const
{
    return ev.any.timestamp;
}

Display Event::GetKeyboardDisplay() const
{
    return Display(ev.keyboard.display, false);
}

int Event::GetKeyboardKeycode() const
{
    return ev.keyboard.keycode;
}

int Event::GetKeyboardCharacter() const
{
    return ev.keyboard.unichar;
}

int Event::GetKeyboardModifiers() const
{
    return ev.keyboard.modifiers;
}

bool Event::GetKeyboardRepeat() const
{
    return ev.keyboard.repeat;
}

Display Event::GetMouseDisplay() const
{
    return Display(ev.mouse.display, false);
}

int Event::GetMouseX() const
{
    return ev.mouse.x;
}

int Event::GetMouseY() const
{
    return ev.mouse.y;
}

int Event::GetMouseZ() const
{
    return ev.mouse.z;
}

int Event::GetMouseW() const
{
    return ev.mouse.w;
}

int Event::GetMouseDX() const
{
    return ev.mouse.dx;
}

int Event::GetMouseDY() const
{
    return ev.mouse.dy;
}

int Event::GetMouseDZ() const
{
    return ev.mouse.dz;
}

int Event::GetMouseDW() const
{
    return ev.mouse.dw;
}

int Event::GetMouseButton() const
{
    return ev.mouse.button;
}

float Event::GetMousePressure() const
{
    return ev.mouse.pressure;
}

int Event::GetJoystickStick() const
{
    return ev.joystick.stick;
}

int Event::GetJoystickAxis() const
{
    return ev.joystick.axis;
}

float Event::GetJoystickAxisPosition() const
{
    return ev.joystick.pos;
}

int Event::GetJoystickButton() const
{
    return ev.joystick.button;
}

Display Event::GetTouchDisplay() const
{
    return Display(ev.touch.display, false);
}

int Event::GetTouchId() const
{
    return ev.touch.id;
}

float Event::GetTouchX() const
{
    return ev.touch.x;
}

float Event::GetTouchY() const
{
    return ev.touch.y;
}

float Event::GetTouchDX() const
{
    return ev.touch.dx;
}

float Event::GetTouchDY() const
{
    return ev.touch.dy;
}

bool Event::GetTouchPrimary() const
{
    return ev.touch.primary;
}

Display Event::GetDisplay() const
{
    return Display(ev.display.source, false);
}

int Event::GetDisplayX() const
{
    return ev.display.x;
}

int Event::GetDisplayY() const
{
    return ev.display.y;
}

int Event::GetDisplayWidth() const
{
    return ev.display.width;
}

int Event::GetDisplayHeight() const
{
    return ev.display.height;
}

int Event::GetDisplayOrientation() const
{
    return ev.display.orientation;
}

Timer Event::GetTimer() const
{
    return Timer(ev.timer.source, false);
}

int64_t Event::GetTimerCount() const
{
    return ev.timer.count;
}

}
