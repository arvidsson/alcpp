#include "Transform.hpp"

namespace alcpp
{
    
Transform::Transform()
{
    Identity();
}
    
Transform::Transform(const Transform &transform)
{
    al_copy_transform(&Get(), &transform.Get());
}

Transform::Transform(const ALLEGRO_TRANSFORM &transform)
{
    al_copy_transform(&Get(), &transform);
}

Transform& Transform::operator=(const Transform &transform)
{
    if (&transform != this) {
        al_copy_transform(&Get(), &transform.Get());
    }
    return *this;
}

Transform& Transform::operator=(const ALLEGRO_TRANSFORM &transform)
{
    al_copy_transform(&Get(), &transform);
    return *this;
}

void Transform::Use()
{
    al_use_transform(&Get());
}

void Transform::UseAsProjection()
{
    al_use_projection_transform(&Get());
}

void Transform::Invert()
{
    al_invert_transform(&Get());
}

bool Transform::IsInvertible(float tolerance) const
{
    return al_check_inverse(&Get(), tolerance);
}

void Transform::Identity()
{
    al_identity_transform(&Get());
}

void Transform::Translate(float x, float y)
{
    al_translate_transform(&Get(), x, y);
}

void Transform::Scale(float scaleX, float scaleY)
{
    al_scale_transform(&Get(), scaleX, scaleY);
}

void Transform::Rotate(float angle)
{
    al_rotate_transform(&Get(), angle);
}

void Transform::Translate3D(float x, float y, float z)
{
    al_translate_transform_3d(&Get(), x, y, z);
}

void Transform::Scale3D(float scaleX, float scaleY, float scaleZ)
{
    al_scale_transform_3d(&Get(), scaleX, scaleY, scaleZ);
}

void Transform::Rotate3D(float x, float y, float z, float angle)
{
    al_rotate_transform_3d(&Get(), x, y, z, angle);
}

void Transform::Build(float x, float y, float scaleX, float scaleY, float angle)
{
    al_build_transform(&Get(), x, y, scaleX, scaleY, angle);
}

void Transform::BuildCamera(float positionX, float positionY, float positionZ, float lookX, float lookY, float lookZ, float upX, float upY, float upZ)
{
    al_build_camera_transform(&Get(), positionX, positionY, positionZ, lookX, lookY, lookZ, upX, upY, upZ);
}

void Transform::Compose(const Transform &transform)
{
    al_compose_transform(&Get(), &transform.Get());
}

void Transform::MakeOrthographic(float left, float top, float near, float right, float bottom, float far)
{
    al_orthographic_transform(&Get(), left, top, near, right, bottom, far);
}

void Transform::MakePerspective(float left, float top, float near, float right, float bottom, float far)
{
    al_perspective_transform(&Get(), left, top, near, right, bottom, far);
}

void Transform::HorizontalShear(float angle)
{
    al_horizontal_shear_transform(&Get(), angle);
}

void Transform::VerticalShear(float angle)
{
    al_vertical_shear_transform(&Get(), angle);
}

float Transform::TransformX(float x) const
{
    float y;
    al_transform_coordinates(&Get(), &x, &y);
    return x;
}

float Transform::TransformY(float y) const
{
    float x;
    al_transform_coordinates(&Get(), &x, &y);
    return y;
}

std::vector<float> Transform::TransformCoordinates(float x, float y) const
{
    al_transform_coordinates(&Get(), &x, &y);
    return { x, y };
}

std::vector<float> Transform::TransformCoordinates3D(float x, float y, float z) const
{
    al_transform_coordinates_3d(&Get(), &x, &y, &z);
    return { x, y, z };
}

Transform Transform::GetCurrentTransform()
{
    return *al_get_current_transform();
}

Transform Transform::GetCurrentInverseTransform()
{
    return *al_get_current_inverse_transform();
}

Transform Transform::GetCurrentProjectionTransform()
{
    return *al_get_current_projection_transform();
}

/*
void Transform::ResetProjectionTransform()
{
    Transform t;
    t.MakeOrthographic(0.0f, 0.0f, -1.0f, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 1.0f);
    al_set_target_bitmap(bitmap);
    t.UseAsProjection();
}
*/

}