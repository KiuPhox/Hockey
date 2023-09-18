#pragma once
#include "Engine/Collider.h"

class CircleCollider : public Collider
{
public:
    float radius = 1;

    CircleCollider(GameObject *obj, float radius);

    Vector2 getCenter();
};