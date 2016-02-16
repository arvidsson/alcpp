#pragma once

#include "../util/SharedPtr.hpp"
#include <allegro5/allegro.h>

namespace alcpp
{

class EventSource : public SharedPtr<ALLEGRO_EVENT_SOURCE>
{
public:
    EventSource(ALLEGRO_EVENT_SOURCE *eventSource) : SharedPtr(eventSource, nullDeleter) {}
};

}