#pragma once
#include "Engine/Vector2.h"
#include <vector>

class CollisionManifold
{
public:
    CollisionManifold();
    CollisionManifold(Vector2 normal, float depth);
    void addContactPoint(Vector2 contact);
    Vector2 getNormal();
    void setNormal(Vector2 normal);
    std::vector<Vector2> getContactPoints();
    float getDepth();
    bool isColliding;

private:
    Vector2 normal;
    std::vector<Vector2> contactPoints;
    float depth;
};