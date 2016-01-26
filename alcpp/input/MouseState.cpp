#include "MouseState.hpp"

namespace alcpp
{

void MouseState::Poll()
{
    al_get_mouse_state(&state);
}

bool MouseState::IsButtonDown(int button)
{
    return al_mouse_button_down(&state, button);
}

int MouseState::GetX() const
{
    return state.x;
}

int MouseState::GetY() const
{
    return state.y;
}

int MouseState::GetZ() const
{
    return state.z;
}

int MouseState::GetW() const
{
    return state.w;
}

float MouseState::GetPressure() const
{
    return state.pressure;
}

}