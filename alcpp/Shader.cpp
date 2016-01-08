#include "Shader.hpp"
#include "Transform.hpp"
#include "Bitmap.hpp"

namespace alcpp
{

Shader::Shader(Platform platform) : SharedPtr(al_create_shader((ALLEGRO_SHADER_PLATFORM)platform), al_destroy_shader) {}
    
bool Shader::AttachSource(Type type, const std::string source)
{
    return al_attach_shader_source(get(), (ALLEGRO_SHADER_TYPE)type, source.c_str());
}

bool Shader::AttachSourceFile(Type type, const std::string filename)
{
    return al_attach_shader_source_file(get(), (ALLEGRO_SHADER_TYPE)type, filename.c_str());
}

bool Shader::Build()
{
    return al_build_shader(get());
}

bool Shader::Use()
{
    return al_use_shader(get());
}

std::string Shader::GetLog() const
{
    return al_get_shader_log(get());
}

Shader::Platform Shader::GetPlatform() const
{
    return (Platform)al_get_shader_platform(get());
}

bool Shader::SetInt(const std::string &name, int i)
{
    return al_set_shader_int(name.c_str(), i);
}

bool Shader::SetFloat(const std::string &name, float f)
{
    return al_set_shader_float(name.c_str(), f);
}

bool Shader::SetBool(const std::string &name, bool b)
{
    return al_set_shader_bool(name.c_str(), b);
}

bool Shader::SetVector(const std::string &name, std::vector<int> &v, int numComponents)
{
    return al_set_shader_int_vector(name.c_str(), v.size(), v.data(), v.size() / numComponents);
}

bool Shader::SetVector(const std::string &name, std::vector<float> &v, int numComponents)
{
    return al_set_shader_float_vector(name.c_str(), v.size(), v.data(), v.size() / numComponents);
}

bool Shader::SetMatrix(const std::string &name, Transform &t)
{
    return al_set_shader_matrix(name.c_str(), &t.Get());
}

bool Shader::SetSampler(const std::string &name, Bitmap &b, int unit)
{
    return al_set_shader_sampler(name.c_str(), b.get(), unit);
}

std::string Shader::GetDefaultSource(Platform platform, Type type)
{
    return al_get_default_shader_source((ALLEGRO_SHADER_PLATFORM)platform, (ALLEGRO_SHADER_TYPE)type);
}

}