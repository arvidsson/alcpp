#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

/*
    Holds snapshot of mouse state. Must be polled every frame.
*/
class MouseState
{
public:
    /*
        Updates the keyboard state.
    */
    void Poll();

    /*
        Returns true if the mouse button is held down.
    */
    bool IsButtonDown(int button);

    /*
        Returns the mouse position.
    */
    int GetX() const;
    int GetY() const;

    /*
        Returns the mouse wheel position.
    */
    int GetZ() const;
    int GetW() const;

    /*
        Returns the mouse wheel pressure.
    */
    float GetPressure() const;

private:
    ALLEGRO_MOUSE_STATE state;
};

}