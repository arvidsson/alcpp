#pragma once

#include "ValueWrapper.hpp"
#include <allegro5/allegro.h>
#include <vector>

namespace alcpp
{

class EventSource;

class Touch : public ValueWrapper<ALLEGRO_TOUCH_INPUT_STATE>
{
public:
    static bool Install();
    static void Uninstall();
    static bool IsInstalled();
    
    static EventSource GetEventSource();
    static EventSource GetMouseEmulationEventSource();
    
    enum MouseEmulationMode
    {
        None = ALLEGRO_MOUSE_EMULATION_NONE,
        Transparent = ALLEGRO_MOUSE_EMULATION_TRANSPARENT,
        Inclusive = ALLEGRO_MOUSE_EMULATION_INCLUSIVE,
        Exclusive = ALLEGRO_MOUSE_EMULATION_EXCLUSIVE,
        BackwardsCompatible50X = ALLEGRO_MOUSE_EMULATION_5_0_x
    };
    
    static void SetMouseEmulationMode(MouseEmulationMode mouseEmulationMode);
    static MouseEmulationMode GetMouseEmulationMode();
    
    struct State
    {
        float x, y;
        float dx, dy;
        bool primary;
    };
    
    void Poll();
    std::vector<State> GetTouches() const;
};

}