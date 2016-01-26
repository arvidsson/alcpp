#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

class Event;
class EventSource;

class EventQueue
{
public:
    EventQueue();
    ~EventQueue();

    void Register(EventSource eventSource);
    void Unregister(EventSource eventSource);
    
    void Pause();
    void Resume();
    bool IsPaused() const;

    bool IsEmpty() const;
    void Flush();

    Event GetNextEvent();
    Event PeekNextEvent();
    bool DropNextEvent();
    Event WaitForEvent();
    Event WaitForEvent(float seconds);

    // TODO: add user events

private:
    ALLEGRO_EVENT_QUEUE *queue = nullptr;
};

}
