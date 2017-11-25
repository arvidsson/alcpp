#include "Transform.hpp"

namespace alcpp
{
    
Transform::Transform()
{
    Identity();
}
    
Transform::Transform(const Transform &transform)
{
    al_copy_transform(&GetRef(), &transform.GetRef());
}

Transform::Transform(const ALLEGRO_TRANSFORM &transform)
{
    al_copy_transform(GetPtr(), &transform);
}

Transform& Transform::operator=(const Transform &transform)
{
    if (&transform != this) {
        al_copy_transform(GetPtr(), const_cast<Transform&>(transform).GetPtr());
    }
    return *this;
}

Transform& Transform::operator=(const ALLEGRO_TRANSFORM &transform)
{
    al_copy_transform(GetPtr(), &transform);
    return *this;
}

void Transform::Identity()
{
    al_identity_transform(GetPtr());
}

void Transform::Use()
{
    al_use_transform(GetPtr());
}

void Transform::UseAsProjection()
{
    al_use_projection_transform(GetPtr());
}

void Transform::Invert()
{
    al_invert_transform(GetPtr());
}

bool Transform::IsInvertible(float tolerance) const
{
    return al_check_inverse(const_cast<Transform&>(*this).GetPtr(), tolerance);
}

void Transform::Translate(float x, float y)
{
    al_translate_transform(GetPtr(), x, y);
}

void Transform::Scale(float scaleX, float scaleY)
{
    al_scale_transform(GetPtr(), scaleX, scaleY);
}

void Transform::Rotate(float angle)
{
    al_rotate_transform(GetPtr(), angle);
}

void Transform::Translate3D(float x, float y, float z)
{
    al_translate_transform_3d(GetPtr(), x, y, z);
}

void Transform::Scale3D(float scaleX, float scaleY, float scaleZ)
{
    al_scale_transform_3d(GetPtr(), scaleX, scaleY, scaleZ);
}

void Transform::Rotate3D(float x, float y, float z, float angle)
{
    al_rotate_transform_3d(GetPtr(), x, y, z, angle);
}

void Transform::Build(float x, float y, float scaleX, float scaleY, float angle)
{
    al_build_transform(GetPtr(), x, y, scaleX, scaleY, angle);
}

void Transform::BuildCamera(float positionX, float positionY, float positionZ, float lookX, float lookY, float lookZ, float upX, float upY, float upZ)
{
    al_build_camera_transform(GetPtr(), positionX, positionY, positionZ, lookX, lookY, lookZ, upX, upY, upZ);
}

void Transform::Compose(const Transform &transform)
{
    al_compose_transform(GetPtr(), const_cast<Transform&>(transform).GetPtr());
}

void Transform::MakeOrthographic(float left, float top, float near, float right, float bottom, float far)
{
    al_orthographic_transform(GetPtr(), left, top, near, right, bottom, far);
}

void Transform::MakePerspective(float left, float top, float near, float right, float bottom, float far)
{
    al_perspective_transform(GetPtr(), left, top, near, right, bottom, far);
}

void Transform::HorizontalShear(float angle)
{
    al_horizontal_shear_transform(GetPtr(), angle);
}

void Transform::VerticalShear(float angle)
{
    al_vertical_shear_transform(GetPtr(), angle);
}

float Transform::TransformX(float x) const
{
    float y;
    al_transform_coordinates(const_cast<Transform&>(*this).GetPtr(), &x, &y);
    return x;
}

float Transform::TransformY(float y) const
{
    float x;
    al_transform_coordinates(const_cast<Transform&>(*this).GetPtr(), &x, &y);
    return y;
}

std::vector<float> Transform::TransformCoordinates(float x, float y) const
{
    al_transform_coordinates(const_cast<Transform&>(*this).GetPtr(), &x, &y);
    return { x, y };
}

std::vector<float> Transform::TransformCoordinates3D(float x, float y, float z) const
{
    al_transform_coordinates_3d(const_cast<Transform&>(*this).GetPtr(), &x, &y, &z);
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

}