#include "Display.hpp"
#include "EventSource.hpp"
#include "Color.hpp"

namespace alcpp
{

Display::Display(int width, int height, bool fullscreen)
{
    //al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR | ALLEGRO_MIPMAP);
    /*vsync ? al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_REQUIRE) : al_set_new_display_option(ALLEGRO_VSYNC, 2, ALLEGRO_REQUIRE);
    if (multisampling) {
    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_REQUIRE);
    al_set_new_display_option(ALLEGRO_SAMPLES, multisampling, ALLEGRO_REQUIRE);
    }*/

    fullscreen ? al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW) : al_set_new_display_flags(ALLEGRO_WINDOWED);
    reset(al_create_display(width, height), al_destroy_display);
}

Display::Display(ALLEGRO_DISPLAY *display, bool managed) : SharedPtr(display, managed, al_destroy_display) {}

int Display::GetWidth() const
{
    return al_get_display_width(get());
}

int Display::GetHeight() const
{
    return al_get_display_height(get());
}

void Display::SetTitle(const std::string &title)
{
    al_set_window_title(get(), title.c_str());
}

EventSource Display::GetEventSource() const
{
    return EventSource(al_get_display_event_source(get()));
}

void Display::SetAsTarget()
{
    al_set_target_backbuffer(get());
}

void Display::Clear(const Color &color)
{
    al_clear_to_color(color.ToAllegroColor());
}

void Display::Flip()
{
    al_flip_display();
}

bool Display::HideMouse()
{
    return al_hide_mouse_cursor(get());
}

bool Display::ShowMouse()
{
    return al_show_mouse_cursor(get());
}

bool Display::GrabMouse()
{
    return al_grab_mouse(get());
}

bool Display::UngrabMouse()
{
    return al_ungrab_mouse();
}

}