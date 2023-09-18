#include "Engine/CollisionManifold.h"

CollisionManifold::CollisionManifold()
{
    this->normal = Vector2(0, 0);
    this->contactPoints = std::vector<Vector2>();
    this->depth = 0;
    this->isColliding = false;
}

CollisionManifold::CollisionManifold(Vector2 normal, float depth)
{
    this->normal = normal;
    this->contactPoints = std::vector<Vector2>();
    this->depth = depth;
    this->isColliding = true;
}

void CollisionManifold::addContactPoint(Vector2 contact)
{
    this->contactPoints.push_back(contact);
}

Vector2 CollisionManifold::getNormal()
{
    return this->normal;
}

std::vector<Vector2> CollisionManifold::getContactPoints()
{
    return this->contactPoints;
}

float CollisionManifold::getDepth()
{
    return this->depth;
}
