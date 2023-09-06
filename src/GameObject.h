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

    SDL_Rect rect;
    Vector2 pos;

    float getAngle()
    {
        return angle;
    }
    Vector2 getScale()
    {
        return scale;
    }
    SDL_Texture *getTex();

    void setScale(float w, float h);
    void setAngle(float angle);

    void update(double deltaTime);

    void onCollision(GameObject *other);

private:
protected:
    float angle = 0;
    Vector2 scale = Vector2(1, 1);
    SDL_Texture *tex;
};