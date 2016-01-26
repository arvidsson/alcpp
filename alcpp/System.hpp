#pragma once

#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class System
{
public:
    static void Initialize();

    static bool Install(int (*atexit)(void (*)(void)));
    static void Uninstall();
    static bool IsInstalled();

    static int GetAllegroVersion();
    static std::string GetAllegroVersionString();

    // TODO: GetStandardPath()
    // TODO: GetSystemConfig()

    static void SetExeName(const std::string &name);
    static void SetAppName(const std::string &name);
    static void SetOrgName(const std::string &name);
    static std::string GetAppName();
    static std::string GetOrgName();

    // TODO: RegisterAssertHandler()
    // TODO: RegisterTraceHandler()
};

}