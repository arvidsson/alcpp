#pragma once

#include "../util/SharedWrapper.hpp"
#include <allegro5/allegro.h>

namespace alcpp
{

class EventSource;

class Timer : public SharedWrapper<ALLEGRO_TIMER>
{
public:
    Timer() {}
    Timer(double secondsPerTick);
    Timer(ALLEGRO_TIMER *timer, bool retain = true);

    void Create(double secondsPerTick);
    void Start();
    void Stop();
    void Resume();
    bool IsStarted() const;

    EventSource GetEventSource() const;

    int64_t GetCount() const;
    void SetCount(int64_t count);
    void AddCount(int64_t diff);

    double GetSpeed() const;
    void SetSpeed(double speed);
};

}