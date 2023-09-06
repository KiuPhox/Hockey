#include "Collider.h"

std::vector<Collider *> Collider::colliders;

Collider::Collider(GameObject *obj)
{
    gameObject = obj;
    colliders.push_back(this);
}

void Collider::update()
{
    if (_type == COLLIDER_RECT)
    {
        //
    }
}
