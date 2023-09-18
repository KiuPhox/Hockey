#include "Engine/Collisions.h"
#include <math.h>

CollisionManifold Collisions::findCollisionFeatures(Collider *a, Collider *b)
{
    if (dynamic_cast<CircleCollider *>(a) != nullptr && dynamic_cast<CircleCollider *>(b) != nullptr)
    {
        return findCollisionFeatures((CircleCollider *)a, (CircleCollider *)b);
    }
    else if (dynamic_cast<AABBCollider *>(a) != nullptr && dynamic_cast<AABBCollider *>(b) != nullptr)
    {
        return findCollisionFeatures((AABBCollider *)a, (AABBCollider *)b);
    }
    else if (dynamic_cast<CircleCollider *>(a) != nullptr && dynamic_cast<AABBCollider *>(b) != nullptr)
    {
        return findCollisionFeatures((CircleCollider *)a, (AABBCollider *)b);
    }
    else if (dynamic_cast<AABBCollider *>(a) != nullptr && dynamic_cast<CircleCollider *>(b) != nullptr)
    {
        return findCollisionFeatures((AABBCollider *)a, (CircleCollider *)b);
    }

    return CollisionManifold();
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

CollisionManifold Collisions::findCollisionFeatures(AABBCollider *a, AABBCollider *b)
{
    CollisionManifold result = CollisionManifold();
    Vector2 aMax = a->getMax();
    Vector2 aMin = a->getMin();
    Vector2 bMax = b->getMax();
    Vector2 bMin = b->getMin();

    if (aMax.x < bMin.x || aMin.x > bMax.x)
    {
        return result;
    }

    if (aMax.y < bMin.y || aMin.y > bMax.y)
    {
        return result;
    }

    float xOverlap = std::min(aMax.x, bMax.x) - std::max(aMin.x, bMin.x);
    float yOverlap = std::min(aMax.y, bMax.y) - std::max(aMin.y, bMin.y);

    float depth = std::min(xOverlap, yOverlap);
    Vector2 normal = Vector2(0, 0);

    if (xOverlap < yOverlap)
    {
        normal = Vector2(1, 0);
        if (aMin.x > bMin.x)
        {
            normal = Vector2(-1, 0);
        }
    }
    else
    {
        normal = Vector2(0, 1);
        if (aMin.y > bMin.y)
        {
            normal = Vector2(0, -1);
        }
    }

    Vector2 contactPoint = aMin + (normal * depth);

    result = CollisionManifold(normal, depth);
    result.addContactPoint(contactPoint);
    return result;
}

CollisionManifold Collisions::findCollisionFeatures(CircleCollider *a, AABBCollider *b)
{
    CollisionManifold result = CollisionManifold();
    Vector2 aCenter = a->getCenter();
    Vector2 bMax = b->getMax();
    Vector2 bMin = b->getMin();

    if (aCenter.x < bMin.x)
    {
        aCenter.x = bMin.x;
    }
    else if (aCenter.x > bMax.x)
    {
        aCenter.x = bMax.x;
    }

    if (aCenter.y < bMin.y)
    {
        aCenter.y = bMin.y;
    }
    else if (aCenter.y > bMax.y)
    {
        aCenter.y = bMax.y;
    }

    Vector2 distance = aCenter - a->getCenter();
    if (distance.LengthSqr() > a->radius * a->radius)
    {
        return result;
    }

    float depth = abs(a->radius - distance.Magnitude());
    Vector2 normal = distance.Normalized();
    float distanceToPoint = a->radius - depth;
    Vector2 contactPoint = a->getCenter() + normal * distanceToPoint;

    result = CollisionManifold(normal, depth);
    result.addContactPoint(contactPoint);
    return result;
}

CollisionManifold Collisions::findCollisionFeatures(AABBCollider *a, CircleCollider *b)
{
    CollisionManifold result = findCollisionFeatures(b, a);
    result.setNormal(result.getNormal() * -1);
    return result;
}