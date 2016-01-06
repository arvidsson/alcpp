#include "EventQueue.hpp"
#include "EventSource.hpp"
#include "Event.hpp"
#include <stdexcept>

namespace alcpp
{

EventQueue::EventQueue() : SharedPtr(al_create_event_queue(), al_destroy_event_queue) {}

void EventQueue::Register(EventSource eventSource)
{
    al_register_event_source(get(), eventSource.get());
}

void EventQueue::Unregister(EventSource eventSource)
{
    al_unregister_event_source(get(), eventSource.get());
}

void EventQueue::Pause()
{
    al_pause_event_queue(get(), true);
}

void EventQueue::Resume()
{
    al_pause_event_queue(get(), false);
}

bool EventQueue::IsPaused() const
{
    return al_is_event_queue_paused(get());
}

bool EventQueue::IsEmpty() const
{
    return al_is_event_queue_empty(get());
}

Event EventQueue::GetNextEvent()
{
    ALLEGRO_EVENT event;
    if (al_get_next_event(get(), &event)) {
        return Event(event);
    }
    return Event();
}

Event EventQueue::PeekNextEvent()
{
    ALLEGRO_EVENT event;
    if (al_peek_next_event(get(), &event)) {
        return Event(event);
    }
    return Event();
}

bool EventQueue::DropNextEvent()
{
    return al_drop_next_event(get());
}

void EventQueue::Flush()
{
    al_flush_event_queue(get());
}

Event EventQueue::WaitForEvent()
{
    ALLEGRO_EVENT event;
    al_wait_for_event(get(), &event);
    return Event(event);
}

Event EventQueue::WaitForEventUntil(float seconds)
{
    ALLEGRO_EVENT event;
    if (al_wait_for_event_timed(get(), &event, seconds)) {
        return Event(event);
    }
    return Event();
}

}