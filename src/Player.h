#pragma once

#include <SDL2/SDL.h>

#include "GameObject.h"
#include "Vector2.h"

class Player : public GameObject
{
public:
    enum TEAM
    {
        RED_TEAM,
        BLUE_TEAM
    };

    TEAM team;
    Player(Vector2 p_pos, SDL_Texture *p_tex, TEAM team);
    void update(double deltaTime);

private:
    bool isActive = false;
};