#pragma once

#include "../util/SharedWrapper.hpp"
#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class Bitmap : public SharedWrapper<ALLEGRO_BITMAP>
{
public:
    Bitmap() {}
    Bitmap(ALLEGRO_BITMAP *bitmap, bool retain = true);
    Bitmap(int width, int height);
    Bitmap(Bitmap &parent, int x, int y, int width, int height);
    Bitmap(const std::string &filename);

    Bitmap Clone() const;

    int GetWidth() const;
    int GetHeight() const;

    bool IsLocked() const;
    bool IsSubBitmap() const;
    bool IsCompatible() const;

    void SetAsTarget() const;
    
    bool Load(const std::string &filename);
    bool Save(const std::string &filename) const;

    // TODO: create bitmap from primitives
};

}