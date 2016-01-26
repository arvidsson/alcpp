#include "KeyboardState.hpp"

namespace alcpp
{

void KeyboardState::Poll()
{
    al_get_keyboard_state(&state);
}

bool KeyboardState::IsKeyDown(int keycode)
{
    return al_key_down(&state, keycode);
}

}