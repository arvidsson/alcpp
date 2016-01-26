#pragma once

#include <allegro5/allegro.h>
#include <string>
#include <vector>

namespace alcpp
{

class Transform;
class Bitmap;

class Shader
{
public:
    enum class Platform
    {
        GLSL = ALLEGRO_SHADER_GLSL,
        HLSL = ALLEGRO_SHADER_HLSL
    };

    Shader(Platform platform = Platform::GLSL);
    ~Shader();

    enum class Type
    {
        Vertex = ALLEGRO_VERTEX_SHADER,
        Pixel = ALLEGRO_PIXEL_SHADER
    };
    
    bool AttachSource(Type type, const std::string &source);
    bool AttachSourceFile(Type type, const std::string &filename);
    
    bool Build();
    bool Use();
    
    std::string GetLog() const;
    Platform GetPlatform() const;
    
    bool SetInt(const std::string &name, int i);
    bool SetFloat(const std::string &name, float f);
    bool SetBool(const std::string &name, bool b);
    bool SetVector(const std::string &name, std::vector<int> &v, int numComponents);
    bool SetVector(const std::string &name, std::vector<float> &v, int numComponents);
    bool SetMatrix(const std::string &name, Transform &t);
    bool SetSampler(const std::string &name, Bitmap &b, int unit);
    
    static std::string GetDefaultSource(Platform platform, Type type);

private:
    ALLEGRO_SHADER *shader = nullptr;
};

}