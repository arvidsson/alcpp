#pragma once

#include "ValueWrapper.hpp"
#include <allegro5/allegro.h>

namespace alcpp
{

class EventSource;

class Event : public ValueWrapper<ALLEGRO_EVENT>
{
public:
    Event() {}
    Event(const ALLEGRO_EVENT &event) : ValueWrapper(event), valid(true) {}
    bool IsValid() const;
    operator bool() const;

    enum Type : unsigned int
    {
        JoystickAxis = ALLEGRO_EVENT_JOYSTICK_AXIS,
        JoystickButtonDown = ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN,
        JoystickButtonUp = ALLEGRO_EVENT_JOYSTICK_BUTTON_UP,
        JoystickConfiguration = ALLEGRO_EVENT_JOYSTICK_CONFIGURATION,
        KeyDown = ALLEGRO_EVENT_KEY_DOWN,
        KeyUp = ALLEGRO_EVENT_KEY_UP,
        KeyChar = ALLEGRO_EVENT_KEY_CHAR,
        MouseAxes = ALLEGRO_EVENT_MOUSE_AXES,
        MouseButtonDown = ALLEGRO_EVENT_MOUSE_BUTTON_DOWN,
        MouseButtonUp = ALLEGRO_EVENT_MOUSE_BUTTON_UP,
        MouseWarped = ALLEGRO_EVENT_MOUSE_WARPED,
        MouseEnterDisplay = ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY,
        MouseLeaveDisplay = ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY,
        TouchBegin = ALLEGRO_EVENT_TOUCH_BEGIN,
        TouchEnd = ALLEGRO_EVENT_TOUCH_END,
        TouchMove = ALLEGRO_EVENT_TOUCH_MOVE,
        TouchCancel = ALLEGRO_EVENT_TOUCH_CANCEL,
        Timer = ALLEGRO_EVENT_TIMER,
        DisplayExpose = ALLEGRO_EVENT_DISPLAY_EXPOSE,
        DisplayResize = ALLEGRO_EVENT_DISPLAY_RESIZE,
        DisplayClose = ALLEGRO_EVENT_DISPLAY_CLOSE,
        DisplayLost = ALLEGRO_EVENT_DISPLAY_LOST,
        DisplayFound = ALLEGRO_EVENT_DISPLAY_FOUND,
        DisplaySwitchOut = ALLEGRO_EVENT_DISPLAY_SWITCH_OUT,
        DisplaySwitchIn = ALLEGRO_EVENT_DISPLAY_SWITCH_IN,
        DisplayOrientation = ALLEGRO_EVENT_DISPLAY_ORIENTATION,
        DisplayHaltDrawing = ALLEGRO_EVENT_DISPLAY_HALT_DRAWING,
        DisplayResumeDrawing = ALLEGRO_EVENT_DISPLAY_RESUME_DRAWING,
        DisplayConnected = ALLEGRO_EVENT_DISPLAY_CONNECTED,
        DisplayDisconnected = ALLEGRO_EVENT_DISPLAY_CONNECTED
    };

    Type GetType() const;
    EventSource GetEventSource() const;
    double GetTimestamp() const;

    // keyboard
    int GetKeyboardKeycode() const;
    int GetKeyboardCharacter() const;
    int GetKeyboardModifiers() const;
    bool GetKeyboardRepeat() const;

    // mouse
    int GetMouseX() const;
    int GetMouseY() const;
    int GetMouseZ() const;
    int GetMouseW() const;
    int GetMouseDX() const;
    int GetMouseDY() const;
    int GetMouseDZ() const;
    int GetMouseDW() const;
    int GetMouseButton() const;
    float GetMousePressure() const;

    // joystick
    int GetJoystickStick() const;
    int GetJoystickAxis() const;
    float GetJoystickAxisPosition() const;
    int GetJoystickButton() const;

    // TODO: add display events
    // TODO: add joystick events
    // TODO: add touch events

private:
    bool valid = false;
};

}
