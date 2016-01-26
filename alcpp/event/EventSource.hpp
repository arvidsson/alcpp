#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

class EventSource
{
public:
    EventSource(ALLEGRO_EVENT_SOURCE *eventSource) : source(eventSource) {}
    ~EventSource() {}

    ALLEGRO_EVENT_SOURCE* Get() { return source; }

private:
    ALLEGRO_EVENT_SOURCE *source = nullptr;
};

}