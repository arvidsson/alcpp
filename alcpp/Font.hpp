#pragma once

#include "SharedPtr.hpp"
#include <allegro5/allegro_font.h>
#include <string>
#include <vector>
#include <tuple>

namespace alcpp
{

class Bitmap;

class Font : public SharedPtr<ALLEGRO_FONT>
{
public:
    Font() {}
    Font(ALLEGRO_FONT *font, bool managed = true);
    Font(const std::string &filename, int size, int flags = 0);
    Font(const std::string &filename);
    
    bool Load(const std::string &filename, int size, int flags = 0);
    bool LoadBitmapFont(const std::string &filename);
    bool GrabFromBitmap(const Bitmap &bitmap, const std::vector<std::tuple<int, int>> &ranges);
};

}