#include "Timer.hpp"
#include "../event/EventSource.hpp"
#include <stdexcept>

namespace alcpp
{

Timer::Timer(double secondsPerTick)
{
    timer = al_create_timer(secondsPerTick);
    if (!timer) {
        throw std::runtime_error("Failed to create timer");
    }
}

Timer::~Timer()
{
    if (managed) {
        al_destroy_timer(timer);
    }
}

Timer::Timer(ALLEGRO_TIMER *timer, bool managed) : timer(timer), managed(managed) {}

void Timer::Start()
{
    al_start_timer(timer);
}

void Timer::Stop()
{
    al_stop_timer(timer);
}

void Timer::Resume()
{
    al_resume_timer(timer);
}

bool Timer::IsStarted() const
{
    return al_get_timer_started(timer);
}

EventSource Timer::GetEventSource() const
{
    return EventSource(al_get_timer_event_source(timer));
}

int64_t Timer::GetCount() const
{
    return al_get_timer_count(timer);
}

void Timer::SetCount(int64_t count)
{
    al_set_timer_count(timer, count);
}

void Timer::AddCount(int64_t diff)
{
    al_add_timer_count(timer, diff);
}

double Timer::GetSpeed() const
{
    return al_get_timer_speed(timer);
}

void Timer::SetSpeed(double speed)
{
    al_set_timer_speed(timer, speed);
}

}