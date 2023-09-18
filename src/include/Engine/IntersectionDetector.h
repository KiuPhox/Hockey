#pragma once

#include "Engine/Line.h"
#include "Engine/CircleCollider.h"
#include "Engine/AABBCollider.h"

class IntersectionDetector
{
public:
    static bool pointOnLine(Vector2 point, Line line);
    static bool pointInCircle(Vector2 point, CircleCollider circle);
    static bool pointInAABB(Vector2 point, AABBCollider box);
    static bool circleAndCircle(CircleCollider c1, CircleCollider c2);
    static bool circleAndAABB(CircleCollider circle, AABBCollider box);
    static bool AABBAndCircle(AABBCollider box, CircleCollider circle);
    static bool AABBAndAABB(AABBCollider b1, AABBCollider b2);

private:
    static bool overlapOnAxis(AABBCollider b1, AABBCollider b2, Vector2 axis);
    static Vector2 getInterval(AABBCollider box, Vector2 axis);
};