#include "EventQueue.hpp"
#include "EventSource.hpp"
#include "Event.hpp"
#include <stdexcept>

namespace alcpp
{

EventQueue::EventQueue()
{
    queue = al_create_event_queue();
    if (!queue) {
        throw std::runtime_error("Failed to create event queue");
    }
}

EventQueue::~EventQueue()
{
    al_destroy_event_queue(queue);
}

void EventQueue::Register(EventSource eventSource)
{
    al_register_event_source(queue, eventSource.Get());
}

void EventQueue::Unregister(EventSource eventSource)
{
    al_unregister_event_source(queue, eventSource.Get());
}

void EventQueue::Pause()
{
    al_pause_event_queue(queue, true);
}

void EventQueue::Resume()
{
    al_pause_event_queue(queue, false);
}

bool EventQueue::IsPaused() const
{
    return al_is_event_queue_paused(queue);
}

bool EventQueue::IsEmpty() const
{
    return al_is_event_queue_empty(queue);
}

void EventQueue::Flush()
{
    al_flush_event_queue(queue);
}

Event EventQueue::GetNextEvent()
{
    ALLEGRO_EVENT event;
    if (al_get_next_event(queue, &event)) {
        return Event(event);
    }
    return Event();
}

Event EventQueue::PeekNextEvent()
{
    ALLEGRO_EVENT event;
    if (al_peek_next_event(queue, &event)) {
        return Event(event);
    }
    return Event();
}

bool EventQueue::DropNextEvent()
{
    return al_drop_next_event(queue);
}

Event EventQueue::WaitForEvent()
{
    ALLEGRO_EVENT event;
    al_wait_for_event(queue, &event);
    return Event(event);
}

Event EventQueue::WaitForEvent(float seconds)
{
    ALLEGRO_EVENT event;
    if (al_wait_for_event_timed(queue, &event, seconds)) {
        return Event(event);
    }
    return Event();
}

}