#include "Engine/RigidBody.h"
#include "Engine/GameObject.h"

RigidBody::RigidBody(GameObject *obj) : Component(obj)
{
    this->position = obj->position;
    this->lastPosition = this->position;
    this->acceleration = Vector2(0, 0);
}

void RigidBody::update(double deltaTime)
{
    Vector2 displacement = this->position - this->lastPosition;
    this->lastPosition = this->position;
    this->position += displacement + this->acceleration * deltaTime * deltaTime;
    this->acceleration = Vector2(0, 0);
}

void RigidBody::accelerate(Vector2 force)
{
    this->acceleration += force;
}

void RigidBody::setVelocity(Vector2 v, double deltaTime)
{
    this->position = this->position + v * deltaTime;
}

void RigidBody::addVelocity(Vector2 v, double deltaTime)
{
    this->position = this->position + v * deltaTime;
}

Vector2 RigidBody::getVelocity(double deltaTime)
{
    return (this->position - this->lastPosition) / deltaTime;
}
