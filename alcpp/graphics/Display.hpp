#pragma once

#include "../util/SharedPtr.hpp"
#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class EventSource;
class Color;
class Bitmap;

class Display : public SharedPtr<ALLEGRO_DISPLAY>
{
public:
    Display() {}
    Display(int width, int height, bool fullscreen = false);
    Display(ALLEGRO_DISPLAY *display, bool managed = true);

    int GetWidth() const;
    int GetHeight() const;

    void SetTitle(const std::string &title);

    EventSource GetEventSource() const;

    void SetAsTarget();
    void Clear(const Color& color);
    void Flip();

    enum DrawFlags
    {
        None = 0,
        FlipHorizontal = ALLEGRO_FLIP_HORIZONTAL,
        FlipVertical = ALLEGRO_FLIP_VERTICAL
    };

    // drawing operations
    void Draw(Bitmap &bitmap, float destX, float destY, DrawFlags flags = DrawFlags::None);
    void DrawTinted(Bitmap &bitmap, Color &color, float destX, float destY, DrawFlags flags = DrawFlags::None);
    void DrawRegion(Bitmap &bitmap, float srcX, float srcY, float srcWidth, float srcHeight, float destX, float destY, DrawFlags flags = DrawFlags::None);
    void DrawTintedRegion(Bitmap &bitmap, Color &color, float srcX, float srcY, float srcWidth, float srcHeight, float destX, float destY, DrawFlags flags = DrawFlags::None);
    void DrawRotated(Bitmap &bitmap, float centerX, float centerY, float destX, float destY, float angle, DrawFlags flags = DrawFlags::None);
    void DrawTintedRotated(Bitmap &bitmap, Color &color, float centerX, float centerY, float destX, float destY, float angle, DrawFlags flags = DrawFlags::None);
    void DrawScaled(Bitmap &bitmap, float srcX, float srcY, float srcWidth, float srcHeight, float destX, float destY, float destWidth, float destHeight, DrawFlags flags = DrawFlags::None);
    void DrawTintedScaled(Bitmap &bitmap, Color &color, float srcX, float srcY, float srcWidth, float srcHeight, float destX, float destY, float destWidth, float destHeight, DrawFlags flags = DrawFlags::None);
    void DrawScaledRotated(Bitmap &bitmap, float centerX, float centerY, float destX, float destY, float scaleX, float scaleY, float angle, DrawFlags flags = DrawFlags::None);
    void DrawTintedScaledRotated(Bitmap &bitmap, Color &color, float centerX, float centerY, float destX, float destY, float scaleX, float scaleY, float angle, DrawFlags flags = DrawFlags::None);
    void HoldDrawing();
    void ReleaseDrawing();
    bool IsDrawingHeld() const;

    bool HideMouse();
    bool ShowMouse();
    bool GrabMouse();
    bool UngrabMouse();

    enum Orientation
    {
        ZeroDegrees = ALLEGRO_DISPLAY_ORIENTATION_0_DEGREES,
        NinetyDegrees = ALLEGRO_DISPLAY_ORIENTATION_90_DEGREES,
        OneHundredEightyDegrees = ALLEGRO_DISPLAY_ORIENTATION_180_DEGREES,
        TwoHundredSeventyDegrees = ALLEGRO_DISPLAY_ORIENTATION_270_DEGREES,
        FaceUp = ALLEGRO_DISPLAY_ORIENTATION_FACE_UP,
        FaceDown = ALLEGRO_DISPLAY_ORIENTATION_FACE_DOWN
    };

    // TODO: custom mouse cursor from Bitmap
    // TODO: set system mouse cursor
    // TODO: set mouse xy
};

}