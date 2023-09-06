#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.h"

class GameObject
{
public:
    GameObject(Vector2 p_pos, SDL_Texture *p_tex);
    Vector2 &getPos()
    {
        return pos;
    }
    float getAngle()
    {
        return angle;
    }
    Vector2 getScale()
    {
        return scale;
    }
    void setPos(float x, float y);
    void setScale(float w, float h);
    void setAngle(float angle);

    SDL_Texture *getTex();
    SDL_Rect getCurrentFrame();

    void update(double deltaTime);

private:
    Vector2 pos;
    float angle = 0;
    Vector2 scale = Vector2(1, 1);
    SDL_Rect currentFrame;
    SDL_Texture *tex;
};