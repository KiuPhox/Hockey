#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Vector2.h"

class GameObject
{
public:
    static std::vector<GameObject *> gameObjects;
    GameObject(Vector2 p_pos, SDL_Texture *p_tex);

    Vector2 position;
    float angle = 0;
    Vector2 scale = Vector2(1, 1);

    SDL_Rect rect;
    SDL_Texture *tex;

    void update(double deltaTime);

    void onCollision(GameObject *other);

private:
};