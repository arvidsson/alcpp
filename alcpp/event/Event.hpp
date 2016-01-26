#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

class EventSource;
class Display;
class Timer;

class Event
{
public:
    Event() {}
    Event(const ALLEGRO_EVENT &event) : ev(event), valid(true) {}
    bool IsValid() const;
    operator bool() const;

    enum class Type : unsigned int
    {
        KeyDown = ALLEGRO_EVENT_KEY_DOWN,
        KeyUp = ALLEGRO_EVENT_KEY_UP,
        KeyChar = ALLEGRO_EVENT_KEY_CHAR,
        MouseAxes = ALLEGRO_EVENT_MOUSE_AXES,
        MouseButtonDown = ALLEGRO_EVENT_MOUSE_BUTTON_DOWN,
        MouseButtonUp = ALLEGRO_EVENT_MOUSE_BUTTON_UP,
        MouseWarped = ALLEGRO_EVENT_MOUSE_WARPED,
        MouseEnterDisplay = ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY,
        MouseLeaveDisplay = ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY,
        JoystickAxis = ALLEGRO_EVENT_JOYSTICK_AXIS,
        JoystickButtonDown = ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN,
        JoystickButtonUp = ALLEGRO_EVENT_JOYSTICK_BUTTON_UP,
        JoystickConfiguration = ALLEGRO_EVENT_JOYSTICK_CONFIGURATION,
        TouchBegin = ALLEGRO_EVENT_TOUCH_BEGIN,
        TouchEnd = ALLEGRO_EVENT_TOUCH_END,
        TouchMove = ALLEGRO_EVENT_TOUCH_MOVE,
        TouchCancel = ALLEGRO_EVENT_TOUCH_CANCEL,
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
        DisplayDisconnected = ALLEGRO_EVENT_DISPLAY_DISCONNECTED,
        Timer = ALLEGRO_EVENT_TIMER
    };

    Type GetType() const;
    EventSource GetEventSource() const;
    double GetTimestamp() const;

    // keyboard
    Display GetKeyboardDisplay() const;
    int GetKeyboardKeycode() const;
    int GetKeyboardCharacter() const;
    int GetKeyboardModifiers() const;
    bool GetKeyboardRepeat() const;

    // mouse
    Display GetMouseDisplay() const;
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

    // touch
    Display GetTouchDisplay() const;
    int GetTouchId() const;
    float GetTouchX() const;
    float GetTouchY() const;
    float GetTouchDX() const;
    float GetTouchDY() const;
    bool GetTouchPrimary() const;

    // display
    Display GetDisplay() const;
    int GetDisplayX() const;
    int GetDisplayY() const;
    int GetDisplayWidth() const;
    int GetDisplayHeight() const;
    int GetDisplayOrientation() const;

    // timer
    Timer GetTimer() const;
    int64_t GetTimerCount() const;

private:
    ALLEGRO_EVENT ev;
    bool valid = false;
};

}
