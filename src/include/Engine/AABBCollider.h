#pragma once
#include "Engine/Collider.h"

class AABBCollider : public Collider
{
public:
    Vector2 size = Vector2::ZERO;
    Vector2 halfSize = Vector2::ZERO;

    AABBCollider(GameObject *obj);
    AABBCollider(GameObject *obj, Vector2 min, Vector2 max);
    AABBCollider(GameObject *obj, Vector2 size);
    Vector2 getMin();
    Vector2 getMax();

    void setSize(Vector2 size);
};