#pragma once

#include <SDL2/SDL.h>

#include "Engine/GameObject.h"
#include "Engine/Vector2.h"
#include "Engine/RigidBody.h"
#include "Engine/CircleCollider.h"

class Player : public GameObject
{
public:
    enum TEAM
    {
        RED_TEAM,
        BLUE_TEAM
    };

    TEAM team;
    bool active = false;

    void update(float deltaTime) override;

    Player(Vector2 pos, TEAM team, bool active = false);

private:
    RigidBody *rigidBody;
    CircleCollider *collider;

    Vector2 getMovementVector();
    void move(float deltaTime);
};