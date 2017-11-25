#include "Timer.hpp"
#include "../event/EventSource.hpp"
#include <stdexcept>

namespace alcpp
{

Timer::Timer(double secondsPerTick) : SharedWrapper(al_create_timer(secondsPerTick), al_destroy_timer) {}

Timer::Timer(ALLEGRO_TIMER *timer, bool retain) : SharedWrapper(timer, al_destroy_timer, retain) {}

void Timer::Create(double secondsPerTick)
{
    reset(al_create_timer(secondsPerTick), al_destroy_timer);
}

void Timer::Start()
{
    al_start_timer(GetPtr());
}

void Timer::Stop()
{
    al_stop_timer(GetPtr());
}

void Timer::Resume()
{
    al_resume_timer(GetPtr());
}

bool Timer::IsStarted() const
{
    return al_get_timer_started(GetPtr());
}

EventSource Timer::GetEventSource() const
{
    return EventSource(al_get_timer_event_source(GetPtr()));
}

int64_t Timer::GetCount() const
{
    return al_get_timer_count(GetPtr());
}

void Timer::SetCount(int64_t count)
{
    al_set_timer_count(GetPtr(), count);
}

void Timer::AddCount(int64_t diff)
{
    al_add_timer_count(GetPtr(), diff);
}

double Timer::GetSpeed() const
{
    return al_get_timer_speed(GetPtr());
}

void Timer::SetSpeed(double speed)
{
    al_set_timer_speed(GetPtr(), speed);
}

}