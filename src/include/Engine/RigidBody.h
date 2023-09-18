#pragma once

#include "Component.h"
#include "Vector2.h"

class RigidBody : public Component
{
public:
    float mass = 1;
    float inverseMass = 1;

    Vector2 forceAccum = Vector2::ZERO;
    Vector2 linearVelocity = Vector2::ZERO;
    float angularVelocity = 0;
    float linearDamping = 0;
    float angularDamping = 0;

    float cor = 1;
    float friction = 1;

    bool isStatic;

    RigidBody(GameObject *obj);

    void update(float deltaTime) override;
    void setMass(float mass);
    void clearAccumulators();
    void addForce(Vector2 force);
};