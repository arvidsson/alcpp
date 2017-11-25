#pragma once

#include "../util/SharedWrapper.hpp"
#include <allegro5/allegro.h>

namespace alcpp
{

class EventSource : public SharedWrapper<ALLEGRO_EVENT_SOURCE>
{
public:
    EventSource(ALLEGRO_EVENT_SOURCE *eventSource) : SharedWrapper(eventSource, nullDeleter) {}
};

}