#include "Time.hpp"
#include <allegro5/allegro.h>

namespace alcpp
{

double Time::GetTime()
{
    return al_get_time();
}

void Time::Rest(double seconds)
{
    al_rest(seconds);
}

}