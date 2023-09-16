#include "Engine/Collider.h"
#include "Engine/GameObject.h"

std::vector<Collider *> Collider::colliders;

Collider::Collider(GameObject *obj, TYPE_COLLIDER type) : Component(obj)
{
    this->type = type;
    this->size = Vector2(obj->rect.w, obj->rect.h);
    this->radius = 10;
    colliders.push_back(this);
}

void Collider::update(float deltaTime)
{
    //
}

bool Collider::checkCollision(Collider *other)
{
    Vector2 this_pos = this->gameObject->position + this->offset;
    Vector2 other_pos = other->gameObject->position + other->offset;

    if (type == COLLIDER_RECT && type == other->type)
    {

        if (this_pos.x >= other_pos.x + other->size.x || this_pos.x + size.x <= other_pos.x)
            return false;
        if (this_pos.y >= other_pos.y + other->size.y || this_pos.y + size.y <= other_pos.y)
            return false;
        return true;
    }
    else if (type == COLLIDER_CIRCLE && type == other->type)
    {
        return (this_pos - other_pos).Magnitude() >= this->radius + other->radius;
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

        if (type == COLLIDER_CIRCLE)
        {
            rect_half_size = other->size * 0.5f;
            rect_center = other_pos + rect_half_size;
            circle_pos = this_pos;
            radius = other->radius;
        }
        else
        {
            rect_half_size = this->size * 0.5f;
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
