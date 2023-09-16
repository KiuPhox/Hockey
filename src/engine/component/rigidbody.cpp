#include "Engine/RigidBody.h"
#include "Engine/GameObject.h"

RigidBody::RigidBody(GameObject *obj) : Component(obj)
{
    this->velocity = Vector2(0, 0);
    this->friction = 1;
}

void RigidBody::update(float deltaTime)
{
    this->gameObject->position = this->gameObject->position + this->velocity * deltaTime;
    this->velocity = this->velocity * this->friction;
}