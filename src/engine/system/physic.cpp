#include "Engine/Physic.h"
#include "Engine/GameObject.h"

#include <iostream>

Physic::Physic()
{
    //
}

void Physic::update()
{
    for (auto &collider : Collider::colliders)
    {
        for (auto &other : Collider::colliders)
        {
            if (collider != other)
            {
                if (checkCollision(collider, other))
                {
                    collider->gameObject->onCollision(other->gameObject);
                    other->gameObject->onCollision(collider->gameObject);
                }
            }
        }
    }
}

bool Physic::checkCollision(Collider *collider, Collider *other)
{
    Vector2 this_pos = collider->gameObject->position + collider->offset;
    Vector2 other_pos = other->gameObject->position + other->offset;

    if (collider->type == Collider::COLLIDER_RECT && collider->type == other->type)
    {
        if (this_pos.x >= other_pos.x + other->size.x || this_pos.x + collider->size.x <= other_pos.x)
            return false;
        if (this_pos.y >= other_pos.y + other->size.y || this_pos.y + collider->size.y <= other_pos.y)
            return false;

        return true;
    }
    else if (collider->type == Collider::COLLIDER_CIRCLE && collider->type == other->type)
    {

        Vector2 v = this_pos - other_pos;

        float dist = v.GetLength();
        float minDist = collider->radius + other->radius;

        if (dist < minDist)
        {
            // Vector2 n = v / dist;
            // float mass_ratio_1 = collider->radius / minDist;
            // float mass_ratio_2 = other->radius / minDist;

            // float delta = 0.5 * 20 * (dist - minDist);

            // collider->gameObject->position -= n * (mass_ratio_2 * delta);
            // other->gameObject->position += n * (mass_ratio_1 * delta);
            return true;
        }
    }
    else
    {
        Vector2 dist;
        Vector2 rect_center;
        Vector2 rect_half_size;
        Vector2 circle_pos;
        static int radius;
        static float dx;
        static float dy;

        if (collider->type == Collider::COLLIDER_CIRCLE)
        {
            rect_half_size = other->size * 0.5f;
            rect_center = other_pos + rect_half_size;
            circle_pos = this_pos;
            radius = other->radius;
        }
        else
        {
            rect_half_size = collider->size * 0.5f;
            rect_center = this_pos + rect_half_size;
            circle_pos = other_pos;
            radius = other->radius;
        }

        dist.x = fabs(circle_pos.x - rect_center.x);
        dist.y = fabs(circle_pos.y - rect_center.y);

        if (dist.x > (rect_half_size.x + radius))
        {
            return false;
        }
        if (dist.y > (rect_half_size.y + radius))
        {
            return false;
        }

        if (dist.x <= (rect_half_size.x))
        {
            return true;
        }
        if (dist.x <= (rect_half_size.y))
        {
            return true;
        }

        dx = dist.x - rect_half_size.x;
        dy = dist.y - rect_half_size.y;

        return dx * dx + dy * dy <= (radius * radius);
    }

    return false;
}