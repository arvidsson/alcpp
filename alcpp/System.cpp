#include "System.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Joystick.hpp"
#include "Touch.hpp"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_physfs.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_video.h>
#include <stdexcept>

namespace alcpp
{

void System::Init(int addons)
{
    if (!al_init()) {
        throw std::runtime_error("Failed to initialize allegro");
    }

    if (!Keyboard::Install()) {
        throw std::runtime_error("Failed to install keyboard");
    }

    if (!Mouse::Install()) {
        throw std::runtime_error("Failed to install mouse");
    }

    if (!Joystick::Install()) {
        throw std::runtime_error("Failed to install joystick");
    }

    if (!Touch::Install()) {
        throw std::runtime_error("Failed to install touch input");
    }

    if (addons & Addon::Audio) {
        if (!al_install_audio()) {
            throw std::runtime_error("Failed to install audio");
        }
    }

    if (addons & Addon::ACodec) {
        if (!al_init_acodec_addon()) {
            throw std::runtime_error("Failed to initialize acodec addon");
        }
    }

    if (addons & Addon::Font) {
        if (!al_init_font_addon()) {
            throw std::runtime_error("Failed to initialize font addon");
        }
    }

    if (addons & Addon::TTF) {
        if (!al_init_ttf_addon()) {
            throw std::runtime_error("Failed to initialize ttf addon");
        }
    }

    if (addons & Addon::Image) {
        if (!al_init_image_addon()) {
            throw std::runtime_error("Failed to initialize image addon");
        }
    }

    if (addons & Addon::NativeDialog) {
        if (!al_init_native_dialog_addon()) {
            throw std::runtime_error("Failed to initialize native dialogs addon");
        }
    }

    if (addons & Addon::PhysicsFS) {
        al_set_physfs_file_interface();
    }

    if (addons & Addon::Primitives) {
        if (!al_init_primitives_addon()) {
            throw std::runtime_error("Failed to initialize primitives addon");
        }
    }

    if (addons & Addon::Video) {
        if (!al_init_video_addon()) {
            throw std::runtime_error("Failed to initialize video addon");
        }
    }
}

bool System::IsInitialized()
{
    return al_is_system_installed();
}

int System::GetAllegroVersion()
{
    return al_get_allegro_version();
}

std::string System::GetAllegroVersionString()
{
    auto version = GetAllegroVersion();
    int major = version >> 24;
    int minor = (version >> 16) & 255;
    int revision = (version >> 8) & 255;
    std::string versionString = std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(revision);
    return versionString;
}

std::string System::GetStandardPathString(PathType pathType)
{
    return al_path_cstr(al_get_standard_path(pathType), ALLEGRO_NATIVE_PATH_SEP);
}

}