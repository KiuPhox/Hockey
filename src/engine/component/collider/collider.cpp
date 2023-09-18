#include "Engine/Collider.h"
#include "Engine/GameObject.h"

std::vector<Collider *> Collider::colliders;

Collider::Collider(GameObject *obj) : Component(obj)
{
    this->isTrigger = false;
    colliders.push_back(this);
}

void Collider::update(float deltaTime)
{
    //
}
