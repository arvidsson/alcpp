#include "Touch.hpp"
#include "EventSource.hpp"

namespace alcpp
{

bool Touch::Install()
{
    return al_install_touch_input();
}

void Touch::Uninstall()
{
    al_uninstall_touch_input();
}

bool Touch::IsInstalled()
{
    return al_is_touch_input_installed();
}
    
EventSource Touch::GetEventSource()
{
    return al_get_touch_input_event_source();
}

EventSource Touch::GetMouseEmulationEventSource()
{
    return al_get_touch_input_mouse_emulation_event_source();
}

void Touch::SetMouseEmulationMode(MouseEmulationMode mouseEmulationMode)
{
    al_set_mouse_emulation_mode(mouseEmulationMode);
}

Touch::MouseEmulationMode Touch::GetMouseEmulationMode()
{
    return (MouseEmulationMode)al_get_mouse_emulation_mode();
}

void Touch::Poll()
{
    al_get_touch_input_state(&Get());
}

std::vector<Touch::State> Touch::GetTouches() const
{
    std::vector<State> touches;
    
    for (int i = 0; i < ALLEGRO_TOUCH_INPUT_MAX_TOUCH_COUNT; i++) {
        auto touch = &Get().touches[i];
        
        if (touch->id > 0) {
            State state;
            state.x = touch->x;
            state.y = touch->y;
            state.dx = touch->dx;
            state.dy = touch->dy;
            state.primary = touch->primary;
            touches.push_back(state);
        }
    }
    
    return touches;
}

}