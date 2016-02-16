#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

class MouseButton
{
public:
    enum
    {
        One = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Max = Eight,
        Left = One,
        Right = Two,
        Middle = Three
    };
};

}