#pragma once

#include <allegro5/allegro.h>
#include <string>

namespace alcpp
{

class System
{
public:
    enum Addon : uint32_t
    {
        Audio           = 1 << 0,
        ACodec          = 1 << 1,
        Font            = 1 << 2,
        TTF             = 1 << 3,  
        Image           = 1 << 4,
        NativeDialog    = 1 << 5,
        PhysicsFS       = 1 << 6,
        Primitives      = 1 << 7,
        Video           = 1 << 8,
        All             = Audio | ACodec | Font | TTF | Image | NativeDialog | Primitives | Video
    };

    static void Init(int addons = Addon::All);
    static bool IsInitialized();

    static int GetAllegroVersion();
    static std::string GetAllegroVersionString();

    enum PathType
    {
        Resources       = ALLEGRO_RESOURCES_PATH,
        Temp            = ALLEGRO_TEMP_PATH,
        UserHome        = ALLEGRO_USER_HOME_PATH,
        UserDocuments   = ALLEGRO_USER_DOCUMENTS_PATH,
        UserData        = ALLEGRO_USER_DATA_PATH,
        UserSettings    = ALLEGRO_USER_SETTINGS_PATH,
        ExeName         = ALLEGRO_EXENAME_PATH
    };

    static std::string GetStandardPathString(PathType pathType);

    // TODO: return standard path as Path class
    // TODO: return system config as Config class
};

}