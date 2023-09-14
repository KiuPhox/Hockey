#include <iostream>

#include "Game/Ball.h"
#include "Engine/Collider.h"

Ball::Ball(Vector2 p_pos, SDL_Texture *p_tex) : GameObject(p_pos, p_tex)
{
    this->name = "ball";
    new Collider(this);
}

void Ball::update(double deltaTime)
{
}

void Ball::onCollision(GameObject *other)
{
}