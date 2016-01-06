#include "Font.hpp"
#include "Bitmap.hpp"
#include <allegro5/allegro_ttf.h>

namespace alcpp
{

Font::Font(ALLEGRO_FONT *font, bool managed) : SharedPtr(font, managed, al_destroy_font) {}

Font::Font(const std::string &filename, int size, int flags) : SharedPtr(al_load_font(filename.c_str(), size, flags), al_destroy_font) {}

Font::Font(const std::string &filename) : SharedPtr(al_load_bitmap_font(filename.c_str()), al_destroy_font) {}

bool Font::Load(const std::string &filename, int size, int flags)
{
    reset(al_load_font(filename.c_str(), size, flags), al_destroy_font);
    return (bool)(*this);
}

bool Font::LoadBitmapFont(const std::string &filename)
{
    reset(al_load_bitmap_font(filename.c_str()), al_destroy_font);
    return (bool)(*this);
}

bool Font::GrabFromBitmap(const Bitmap &bitmap, const std::vector<std::tuple<int, int>> &ranges)
{
    std::vector<int> rangeBuffer;
    for(auto range : ranges) {
        rangeBuffer.push_back(std::get<0>(range));
        rangeBuffer.push_back(std::get<1>(range));
    }
    reset(al_grab_font_from_bitmap(bitmap.get(), rangeBuffer.size(), rangeBuffer.data()), al_destroy_font);
    return (bool)(*this);
}

}