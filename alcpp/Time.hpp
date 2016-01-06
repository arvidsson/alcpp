#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

class Time
{
public:
    static double GetTime();
    static void Rest(double seconds);
};

}