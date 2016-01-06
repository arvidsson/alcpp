#pragma once

#include "SharedPtr.hpp"
#include <allegro5/allegro.h>

namespace alcpp
{

class EventSource;
class Event;

class EventQueue : public SharedPtr<ALLEGRO_EVENT_QUEUE>
{
public:
    EventQueue();

    void Register(EventSource eventSource);
    void Unregister(EventSource eventSource);
    
    void Pause();
    void Resume();
    bool IsPaused() const;

    bool IsEmpty() const;
    Event GetNextEvent();
    Event PeekNextEvent();
    bool DropNextEvent();
    void Flush();

    Event WaitForEvent();
    Event WaitForEventUntil(float seconds);
};

}
