#pragma once

#include <SDL2/SDL.h>

#include "Engine/GameObject.h"
#include "Engine/Vector2.h"
#include "Engine/RigidBody.h"
#include "Engine/Collider.h"

class Player : public GameObject
{
public:
    enum TEAM
    {
        RED_TEAM,
        BLUE_TEAM
    };

    TEAM team;

    void update(float deltaTime) override;
    void setActive(bool active);

    Player(Vector2 p_pos, SDL_Texture *p_tex, TEAM team);

private:
    bool active = false;
    RigidBody *rigidBody;
    Collider *collider;

    Vector2 getMovementVector();
    void clampPositionToScreenBounds();
    void move(float deltaTime);
};