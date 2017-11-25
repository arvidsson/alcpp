#include "Bitmap.hpp"

namespace alcpp
{

Bitmap::Bitmap(ALLEGRO_BITMAP * bitmap, bool retain) : SharedWrapper(bitmap, al_destroy_bitmap, retain) {}

Bitmap::Bitmap(int width, int height) : SharedWrapper(al_create_bitmap(width, height), al_destroy_bitmap) {}

Bitmap::Bitmap(Bitmap & parent, int x, int y, int width, int height) : SharedWrapper(al_create_sub_bitmap(parent.get(), x, y, width, height), al_destroy_bitmap) {}

Bitmap::Bitmap(const std::string &filename) : SharedWrapper(al_load_bitmap(filename.c_str()), al_destroy_bitmap) {}

Bitmap Bitmap::Clone() const
{
    return al_clone_bitmap(get());
}

int Bitmap::GetWidth() const
{
    return al_get_bitmap_width(get());
}

int Bitmap::GetHeight() const
{
    return al_get_bitmap_height(get());
}

bool Bitmap::IsLocked() const
{
    return al_is_bitmap_locked(get());
}

bool Bitmap::IsSubBitmap() const
{
    return al_is_sub_bitmap(get());
}

bool Bitmap::IsCompatible() const
{
    return al_is_compatible_bitmap(get());
}

void Bitmap::SetAsTarget() const
{
    al_set_target_bitmap(get());
}

bool Bitmap::Load(const std::string &filename)
{
    reset(al_load_bitmap(filename.c_str()), al_destroy_bitmap);
    return (bool)(*this);
}

bool Bitmap::Save(const std::string &filename) const
{
    return al_save_bitmap(filename.c_str(), get());
}

}