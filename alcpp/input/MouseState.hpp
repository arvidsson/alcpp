#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

class MouseState
{
public:
    void Poll();
    bool IsButtonDown(int button);
    int GetX() const;
    int GetY() const;
    int GetZ() const;
    int GetW() const;
    float GetPressure() const;

private:
    ALLEGRO_MOUSE_STATE state;
};

}