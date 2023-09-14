#pragma once

#include "Vector2.h"
#include "Component.h"

class RigidBody : public Component
{
public:
    Vector2 position;
    Vector2 lastPosition;
    Vector2 acceleration;

    RigidBody(GameObject *obj);

    void update(double deltaTime) override;
    void accelerate(Vector2 force);
    void setVelocity(Vector2 v, double deltaTime);
    void addVelocity(Vector2 v, double deltaTime);
    Vector2 getVelocity(double deltaTime);
};