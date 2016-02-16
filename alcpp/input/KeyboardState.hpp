#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

/*
    Holds snapshot of keyboard state. Must be polled every frame.
*/
class KeyboardState
{
public:
    /*
        Updates the keyboard state.
    */
    void Poll();

    /*
        Returns true if the key is held down.
    */
    bool IsKeyDown(int keycode);

    // TODO: get display which had focus on keypress

private:
    ALLEGRO_KEYBOARD_STATE state;
};

}