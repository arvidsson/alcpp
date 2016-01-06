#pragma once

#include "ValueWrapper.hpp"
#include <allegro5/allegro.h>
#include <vector>

namespace alcpp
{

class Transform : public ValueWrapper<ALLEGRO_TRANSFORM>
{
public:
    Transform();
    Transform(const Transform &transform);
    Transform(const ALLEGRO_TRANSFORM &transform);
    Transform& operator=(const Transform &transform);
    Transform& operator=(const ALLEGRO_TRANSFORM &transform);
    
    void Use();
    void UseAsProjection();
    void Invert();
    bool IsInvertible(float tolerance = 0.001f) const;
    void Identity();
    
    void Translate(float x, float y);
    void Scale(float scaleX, float scaleY);
    void Rotate(float angle);
    void Translate3D(float x, float y, float z);
    void Scale3D(float scaleX, float scaleY, float scaleZ);
    void Rotate3D(float x, float y, float z, float angle);
    
    void Build(float x, float y, float scaleX, float scaleY, float angle);
    void BuildCamera(float positionX, float positionY, float positionZ, float lookX, float lookY, float lookZ, float upX, float upY, float upZ);
    void Compose(const Transform &transform);
    void MakeOrthographic(float left, float top, float near, float right, float bottom, float far);
    void MakePerspective(float left, float top, float near, float right, float bottom, float far);
    void HorizontalShear(float angle);
    void VerticalShear(float angle);
    
    float TransformX(float x) const;
    float TransformY(float y) const;
    std::vector<float> TransformCoordinates(float x, float y) const;
    std::vector<float> TransformCoordinates3D(float x, float y, float z) const;
    
    static Transform GetCurrentTransform();
    static Transform GetCurrentInverseTransform();
    static Transform GetCurrentProjectionTransform();
    // TODO: move to Bitmap -> static void ResetProjectionTransform();
};

}