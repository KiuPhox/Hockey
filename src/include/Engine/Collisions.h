#pragma once
#include "Engine/CollisionManifold.h"
#include "Engine/CircleCollider.h"
#include "Engine/AABBCollider.h"

class Collisions
{
public:
    static CollisionManifold findCollisionFeatures(Collider *a, Collider *b);
    static CollisionManifold findCollisionFeatures(CircleCollider *a, CircleCollider *b);
    static CollisionManifold findCollisionFeatures(AABBCollider *a, AABBCollider *b);
    static CollisionManifold findCollisionFeatures(CircleCollider *a, AABBCollider *b);
    static CollisionManifold findCollisionFeatures(AABBCollider *a, CircleCollider *b);
};