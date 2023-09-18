#include "Engine/CircleCollider.h"
#include "Engine/GameObject.h"

CircleCollider::CircleCollider(GameObject *obj, float radius) : Collider(obj)
{
    this->radius = radius;
}

Vector2 CircleCollider::getCenter()
{
    return this->gameObject->position;
}