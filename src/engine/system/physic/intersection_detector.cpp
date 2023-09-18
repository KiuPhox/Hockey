#include "Engine/IntersectionDetector.h"

bool IntersectionDetector::pointOnLine(Vector2 point, Line line)
{
    float dx = line.end.x - line.start.x;
    float dy = line.end.y - line.start.y;
    float m = dy / dx;

    float b = line.end.y - m * line.end.x;

    return point.y == m * point.x + b;
}

bool IntersectionDetector::pointInCircle(Vector2 point, CircleCollider circle)
{
    Vector2 circleCenter = circle.getCenter();
    Vector2 centerToPoint = point - circleCenter;

    return centerToPoint.LengthSqr() <= circle.radius * circle.radius;
}

bool IntersectionDetector::pointInAABB(Vector2 point, AABBCollider box)
{
    Vector2 max = box.getMax();
    Vector2 min = box.getMin();

    return point.x <= max.x && point.x >= min.x &&
           point.y <= max.y && point.y >= min.y;
}

bool IntersectionDetector::circleAndCircle(CircleCollider c1, CircleCollider c2)
{
    Vector2 c1Center = c1.getCenter();
    Vector2 c2Center = c2.getCenter();

    Vector2 centerToCenter = c2Center - c1Center;

    return centerToCenter.LengthSqr() <= (c1.radius + c2.radius) * (c1.radius + c2.radius);
}

bool IntersectionDetector::circleAndAABB(CircleCollider circle, AABBCollider box)
{
    Vector2 circleCenter = circle.getCenter();
    Vector2 max = box.getMax();
    Vector2 min = box.getMin();

    Vector2 closestPoint = circleCenter;

    if (circleCenter.x < min.x)
    {
        closestPoint.x = min.x;
    }
    else if (circleCenter.x > max.x)
    {
        closestPoint.x = max.x;
    }

    if (circleCenter.y < min.y)
    {
        closestPoint.y = min.y;
    }
    else if (circleCenter.y > max.y)
    {
        closestPoint.y = max.y;
    }

    Vector2 circleToBox = circleCenter - closestPoint;

    return circleToBox.LengthSqr() <= circle.radius * circle.radius;
}

bool IntersectionDetector::AABBAndCircle(AABBCollider box, CircleCollider circle)
{
    return circleAndAABB(circle, box);
}

bool IntersectionDetector::AABBAndAABB(AABBCollider b1, AABBCollider b2)
{
    Vector2 axes[4] = {
        Vector2(1, 0),
        Vector2(0, 1),
        Vector2(1, 0),
        Vector2(0, 1),
    };

    for (int i = 0; i < 4; i++)
    {
        if (!overlapOnAxis(b1, b2, axes[i]))
        {
            return false;
        }
    }

    return true;
}

bool IntersectionDetector::overlapOnAxis(AABBCollider b1, AABBCollider b2, Vector2 axis)
{
    Vector2 interval1 = getInterval(b1, axis);
    Vector2 interval2 = getInterval(b2, axis);

    return interval1.x <= interval2.y && interval2.x <= interval1.y;
}

Vector2 IntersectionDetector::getInterval(AABBCollider box, Vector2 axis)
{
    Vector2 result = Vector2::ZERO;
    Vector2 min = box.getMin();
    Vector2 max = box.getMax();

    Vector2 vertices[4] = {
        Vector2(min.x, min.y),
        Vector2(min.x, max.y),
        Vector2(max.x, max.y),
        Vector2(max.x, min.y),
    };

    result.x = axis.Dot(vertices[0]);
    result.y = result.x;

    for (int i = 1; i < 4; i++)
    {
        float projection = axis.Dot(vertices[i]);
        if (projection < result.x)
        {
            result.x = projection;
        }
        if (projection > result.y)
        {
            result.y = projection;
        }
    }

    return result;
}