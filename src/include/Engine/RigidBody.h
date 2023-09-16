#pragma once

#include "Component.h"
#include "Vector2.h"

class RigidBody : public Component
{
public:
    Vector2 velocity;
    float friction = 1;

    RigidBody(GameObject *obj);

    void update(float deltaTime) override;
};