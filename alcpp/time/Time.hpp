#pragma once

namespace alcpp
{

class Time
{
public:
    /*
        Return the number of seconds since allegro was initialized.
    */
    static double GetTime();

    /*
        Waits for the specified number of seconds.
    */
    static void Rest(double seconds);
};

}