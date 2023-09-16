#include <iostream>

#include "Game/Ball.h"
#include "Engine/Collider.h"
#include "Engine/GameMath.h"

const float BOUNCE_FACTOR = 100;

Ball::Ball(Vector2 p_pos, SDL_Texture *p_tex) : GameObject(p_pos, p_tex)
{
    this->name = "ball";
    Collider *collider = new Collider(this, Collider::COLLIDER_CIRCLE);
    collider->radius = 24;
}

void Ball::update(float deltaTime)
{
    GameObject::update(deltaTime);

    if (this->velocity.GetLength() > 0)
    {
        this->position += this->velocity * deltaTime;
        this->velocity = Math::Lerp(this->velocity, Vector2::ZERO, 0.0005f);
    }
}

void Ball::onCollision(GameObject *other)
{
    if (other->name == "player")
    {
        // dynamic cast Player
        Player *player = dynamic_cast<Player *>(other);

        this->velocity += (this->position - player->position).Normalized() + player->velocity;
    }
}