#include "Engine/Collider.h"

std::vector<Collider *> Collider::colliders;

Collider::Collider(GameObject *obj, TYPE_COLLIDER type)
{
    gameObject = obj;
    _type = type;
    this->size = Vector2(obj->rect.w, obj->rect.h);
    colliders.push_back(this);
}

void Collider::update()
{
    for (auto &collider : colliders)
    {
        if (collider == this)
            continue;

        if (checkCollision(collider))
        {
            this->gameObject->onCollision(collider->gameObject);
            collider->gameObject->onCollision(this->gameObject);
        }
    }
}

bool Collider::checkCollision(Collider *other)
{
    Vector2 this_pos = this->gameObject->position + this->offset;
    Vector2 other_pos = other->gameObject->position + other->offset;

    if (_type == COLLIDER_RECT && _type == other->_type)
    {

        if (this_pos.x >= other_pos.x + other->size.x || this_pos.x + size.x <= other_pos.x)
            return false;
        if (this_pos.y >= other_pos.y + other->size.y || this_pos.y + size.y <= other_pos.y)
            return false;
        return true;
    }
    else if (_type == COLLIDER_CIRCLE && _type == other->_type)
    {
        return (this_pos - other_pos).GetLength() >= this->radius + other->radius;
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

        if (_type == COLLIDER_CIRCLE)
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
