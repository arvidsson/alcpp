#pragma once

#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class System
{
public:
    /*
        Initializes allegro. Prefer this over manual install/uninstall.
    */
    static void Initialize();

    /*
        Installs allegro.
    */
    static bool Install(int (*atexit)(void (*)(void)));
    
    /*
        Uninstalls allegro.
    */
    static void Uninstall();

    /*
        Returns true if allegro is installed.
    */
    static bool IsInstalled();

    /*
        Returns allegro version.
    */
    static int GetAllegroVersion();
    static std::string GetAllegroVersionString();

    enum class PathType
    {
        Resources = ALLEGRO_RESOURCES_PATH,
        Temp = ALLEGRO_TEMP_PATH,
        UserHome = ALLEGRO_USER_HOME_PATH,
        UserDocuments = ALLEGRO_USER_DOCUMENTS_PATH,
        UserData = ALLEGRO_USER_DATA_PATH,
        UserSettings = ALLEGRO_USER_SETTINGS_PATH,
        ExeName = ALLEGRO_EXENAME_PATH
    };

    /*
        Returns standard system path.
    */
    std::string GetStandardPathString(PathType pathType);

    // TODO: GetStandardPath() as Path
    // TODO: GetSystemConfig() as Config

    /*
        Getters and setters for exe, app, org - important for standard paths.
    */
    static void SetExeName(const std::string &name);
    static void SetAppName(const std::string &name);
    static void SetOrgName(const std::string &name);
    static std::string GetAppName();
    static std::string GetOrgName();

    // TODO: RegisterAssertHandler()
    // TODO: RegisterTraceHandler()
};

}