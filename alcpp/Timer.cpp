#include "Timer.hpp"
#include "EventSource.hpp"

namespace alcpp
{

Timer::Timer(double secondsPerTick) : SharedPtr(al_create_timer(secondsPerTick), al_destroy_timer) {}

Timer::Timer(ALLEGRO_TIMER *timer, bool managed) : SharedPtr(timer, managed, al_destroy_timer) {}

void Timer::Start()
{
    al_start_timer(get());
}

void Timer::Stop()
{
    al_stop_timer(get());
}

void Timer::Resume()
{
    al_resume_timer(get());
}

bool Timer::IsStarted() const
{
    return al_get_timer_started(get());
}

EventSource Timer::GetEventSource() const
{
    return EventSource(al_get_timer_event_source(get()));
}

int64_t Timer::GetCount() const
{
    return al_get_timer_count(get());
}

void Timer::SetCount(int64_t count)
{
    al_set_timer_count(get(), count);
}

void Timer::AddCount(int64_t diff)
{
    al_add_timer_count(get(), diff);
}

double Timer::GetSpeed() const
{
    return al_get_timer_speed(get());
}

void Timer::SetSpeed(double speed)
{
    al_set_timer_speed(get(), speed);
}

}