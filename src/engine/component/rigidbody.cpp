#include "Engine/RigidBody.h"
#include "Engine/GameObject.h"

#include <iostream>

RigidBody::RigidBody(GameObject *obj) : Component(obj)
{
    this->linearVelocity = Vector2(0, 0);
    this->friction = 1;
    this->isStatic = false;
}

void RigidBody::update(float deltaTime)
{
    if (this->mass == 0)
        return;

    Vector2 acceleration = this->forceAccum * this->inverseMass;
    this->linearVelocity += acceleration * deltaTime;
    this->linearVelocity *= this->friction;

    this->gameObject->position += this->linearVelocity * deltaTime;
    this->gameObject->angle += this->angularVelocity * deltaTime;
    this->clearAccumulators();
}

void RigidBody::setMass(float mass)
{
    this->mass = mass;
    this->inverseMass = 1 / mass;
}

void RigidBody::clearAccumulators()
{
    this->forceAccum = Vector2::ZERO;
}

void RigidBody::addForce(Vector2 force)
{
    this->forceAccum += force;
}