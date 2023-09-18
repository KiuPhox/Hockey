#include "Engine/Collisions.h"
#include <math.h>

CollisionManifold Collisions::findCollisionFeatures(Collider *a, Collider *b)
{
    if (dynamic_cast<CircleCollider *>(a) != nullptr && dynamic_cast<CircleCollider *>(b) != nullptr)
    {
        return findCollisionFeatures((CircleCollider *)a, (CircleCollider *)b);
    }
}

CollisionManifold Collisions::findCollisionFeatures(CircleCollider *a, CircleCollider *b)
{
    CollisionManifold result = CollisionManifold();
    float sumRadii = a->radius + b->radius;
    Vector2 distance = b->getCenter() - a->getCenter();
    if (distance.LengthSqr() > sumRadii * sumRadii)
    {
        return result;
    }

    float depth = abs(sumRadii - distance.Magnitude());
    Vector2 normal = distance.Normalized();
    float distanceToPoint = a->radius - depth;
    Vector2 contactPoint = a->getCenter() + normal * distanceToPoint;

    result = CollisionManifold(normal, depth);
    result.addContactPoint(contactPoint);
    return result;
}