#pragma once

#include <allegro5/allegro.h>

namespace alcpp
{

class EventSource;

class Timer
{
public:
    Timer(double secondsPerTick = 1.0 / 60);
    ~Timer();
    Timer(ALLEGRO_TIMER *timer, bool managed = true);

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

private:
    ALLEGRO_TIMER *timer = nullptr;
    bool managed = true;
};

}