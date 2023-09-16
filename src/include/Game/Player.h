#pragma once

#include <SDL2/SDL.h>

#include "Engine/GameObject.h"
#include "Engine/Vector2.h"

class Player : public GameObject
{
public:
    enum TEAM
    {
        RED_TEAM,
        BLUE_TEAM
    };

    TEAM team;
    Vector2 velocity;

    void update(float deltaTime) override;
    void setActive(bool active);

    Player(Vector2 p_pos, SDL_Texture *p_tex, TEAM team);

private:
    bool active = false;

    Vector2 getMovementVector();
};