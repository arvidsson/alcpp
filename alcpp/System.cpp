#include "System.hpp"
#include "input/Keyboard.hpp"
#include <stdexcept>

namespace alcpp
{

void System::Initialize()
{
    if (!al_init()) {
        throw std::runtime_error("Failed to initialize allegro");
    }

    if (!Keyboard::Install()) {
        throw std::runtime_error("Failed to install keyboard driver");
    }
}

bool System::Install(int(*atexit)(void(*)(void)))
{
    return al_install_system(ALLEGRO_VERSION_INT, atexit);
}

void System::Uninstall()
{
    al_uninstall_system();
}

bool System::IsInstalled()
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

void System::SetExeName(const std::string &name)
{
    al_set_exe_name(name.c_str());
}

void System::SetAppName(const std::string &name)
{
    al_set_app_name(name.c_str());
}

void System::SetOrgName(const std::string &name)
{
    al_set_org_name(name.c_str());
}

std::string System::GetAppName()
{
    return al_get_app_name();
}

std::string System::GetOrgName()
{
    return al_get_org_name();
}

}