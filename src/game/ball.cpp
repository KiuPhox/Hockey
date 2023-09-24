#include <iostream>

#include "Game/Ball.h"
#include "Engine/GameMath.h"
#include "Engine/Sprite.h"

const float BOUNCE_FACTOR = 100;
const float MAX_SPEED = 1000;

Ball::Ball(Vector2 p_pos, SDL_Texture *p_tex) : GameObject(p_pos)
{
    this->name = "ball";

    this->collider = new CircleCollider(this, 20);

    this->rigidBody = new RigidBody(this);
    this->rigidBody->friction = 0.995f;
    this->rigidBody->cor = 5;

    new Sprite(this, p_tex);
}

void Ball::update(float deltaTime)
{
    GameObject::update(deltaTime);
    this->updateAngularVelocity();
    this->limitSpeed(MAX_SPEED);
}

void Ball::updateAngularVelocity()
{
    Vector2 linearVelocity = this->rigidBody->linearVelocity;
    float magnitude = linearVelocity.Magnitude();
    this->rigidBody->angularVelocity = linearVelocity.x > 0 ? -magnitude : magnitude;
}

void Ball::limitSpeed(float maxSpeed)
{
    if (this->rigidBody->linearVelocity.Magnitude() > maxSpeed)
    {
        this->rigidBody->linearVelocity = this->rigidBody->linearVelocity.Normalized() * maxSpeed;
    }
}
