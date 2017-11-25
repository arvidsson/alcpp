#include "Display.hpp"
#include "../event/EventSource.hpp"
#include "Color.hpp"
#include "Bitmap.hpp"

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

Display::Display(ALLEGRO_DISPLAY *display, bool retain) : SharedWrapper(display, al_destroy_display, retain) {}

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

void Display::Clear()
{
    Clear(Color(0, 0, 0));
}

void Display::Clear(const Color &color)
{
    al_clear_to_color(color.ToAllegroColor());
}

void Display::SwapBuffers()
{
    al_flip_display();
}

void Display::Draw(Bitmap &bitmap, float destX, float destY, DrawFlags flags)
{
    al_draw_bitmap(bitmap.get(), destX, destY, flags);
}

void Display::DrawTinted(Bitmap &bitmap, Color &color, float destX, float destY, DrawFlags flags)
{
    al_draw_tinted_bitmap(bitmap.get(), color.ToAllegroColor(), destX, destY, flags);
}

void Display::DrawRegion(Bitmap &bitmap, float srcX, float srcY, float srcWidth, float srcHeight, float destX, float destY, DrawFlags flags)
{
    al_draw_bitmap_region(bitmap.get(), srcX, srcY, srcWidth, srcHeight, destX, destY, flags);
}

void Display::DrawTintedRegion(Bitmap &bitmap, Color &color, float srcX, float srcY, float srcWidth, float srcHeight, float destX, float destY, DrawFlags flags)
{
    al_draw_tinted_bitmap_region(bitmap.get(), color.ToAllegroColor(), srcX, srcY, srcWidth, srcHeight, destX, destY, flags);
}

void Display::DrawRotated(Bitmap &bitmap, float centerX, float centerY, float destX, float destY, float angle, DrawFlags flags)
{
    al_draw_rotated_bitmap(bitmap.get(), centerX, centerY, destX, destY, angle, flags);
}

void Display::DrawTintedRotated(Bitmap &bitmap, Color &color, float centerX, float centerY, float destX, float destY, float angle, DrawFlags flags)
{
    al_draw_tinted_rotated_bitmap(bitmap.get(), color.ToAllegroColor(), centerX, centerY, destX, destY, angle, flags);
}

void Display::DrawScaled(Bitmap &bitmap, float srcX, float srcY, float srcWidth, float srcHeight, float destX, float destY, float destWidth, float destHeight, DrawFlags flags)
{
    al_draw_scaled_bitmap(bitmap.get(), srcX, srcY, srcWidth, srcHeight, destX, destY, destWidth, destHeight, flags);
}

void Display::DrawTintedScaled(Bitmap &bitmap, Color &color, float srcX, float srcY, float srcWidth, float srcHeight, float destX, float destY, float destWidth, float destHeight, DrawFlags flags)
{
    al_draw_tinted_scaled_bitmap(bitmap.get(), color.ToAllegroColor(), srcX, srcY, srcWidth, srcHeight, destX, destY, destWidth, destHeight, flags);
}

void Display::DrawScaledRotated(Bitmap &bitmap, float centerX, float centerY, float destX, float destY, float scaleX, float scaleY, float angle, DrawFlags flags)
{
    al_draw_scaled_rotated_bitmap(bitmap.get(), centerX, centerY, destX, destY, scaleX, scaleY, angle, flags);
}

void Display::DrawTintedScaledRotated(Bitmap &bitmap, Color &color, float centerX, float centerY, float destX, float destY, float scaleX, float scaleY, float angle, DrawFlags flags)
{
    al_draw_tinted_scaled_rotated_bitmap(bitmap.get(), color.ToAllegroColor(), centerX, centerY, destX, destY, scaleX, scaleY, angle, flags);
}

void Display::HoldDrawing()
{
    al_hold_bitmap_drawing(true);
}

void Display::ReleaseDrawing()
{
    al_hold_bitmap_drawing(false);
}

bool Display::IsDrawingHeld() const
{
    return al_is_bitmap_drawing_held();
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