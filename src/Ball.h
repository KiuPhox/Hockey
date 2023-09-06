#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "GameObject.h"
#include "Vector2.h"
#include "Player.h"

class Ball : public GameObject
{
public:
    Ball(Vector2 p_pos, SDL_Texture *p_tex);
    void update(double deltaTime);

private:
    void onCollision(GameObject *other);
};