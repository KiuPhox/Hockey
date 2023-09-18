#pragma once

#include "Collider.h"
#include "CollisionManifold.h"
#include "RigidBody.h"

#include <vector>

class Physic
{
public:
    Physic();

    void update();

private:
    std::vector<RigidBody *> bodies1;
    std::vector<RigidBody *> bodies2;
    std::vector<CollisionManifold> collisions;

    int impulseIterations = 6;

    void applyImpulse(RigidBody *a, RigidBody *b, CollisionManifold &m);
};