#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

class KeyboardState
{
public:
    void Poll();
    bool IsKeyDown(int keycode);

private:
    ALLEGRO_KEYBOARD_STATE state;
};

}