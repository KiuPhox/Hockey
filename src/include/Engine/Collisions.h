#pragma once
#include "Engine/CollisionManifold.h"
#include "Engine/CircleCollider.h"

class Collisions
{
public:
    static CollisionManifold findCollisionFeatures(Collider *a, Collider *b);
    static CollisionManifold findCollisionFeatures(CircleCollider *a, CircleCollider *b);
};