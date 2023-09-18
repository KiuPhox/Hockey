#include "Engine/AABBCollider.h"
#include "Engine/GameObject.h"

AABBCollider::AABBCollider(GameObject *obj) : Collider(obj)
{
    this->size = Vector2(obj->rect.w, obj->rect.h);
    this->halfSize = this->size / 2;
}

AABBCollider::AABBCollider(GameObject *obj, Vector2 min, Vector2 max) : Collider(obj)
{
    this->size = max - min;
    this->halfSize = this->size / 2;
}

Vector2 AABBCollider::getMin()
{
    return this->gameObject->position - this->halfSize;
}

Vector2 AABBCollider::getMax()
{
    return this->gameObject->position + this->halfSize;
}

void AABBCollider::setSize(Vector2 size)
{
    this->size = size;
    this->halfSize = this->size / 2;
}