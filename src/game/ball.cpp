#include <iostream>

#include "Game/Ball.h"
#include "Engine/GameMath.h"

const float BOUNCE_FACTOR = 100;
const float MAX_SPEED = 2000;

Ball::Ball(Vector2 p_pos, SDL_Texture *p_tex) : GameObject(p_pos, p_tex)
{
    this->name = "ball";

    this->collider = new CircleCollider(this, 20);

    this->rigidBody = new RigidBody(this);
    this->rigidBody->friction = 0.999f;
    this->rigidBody->cor = 5;
}

void Ball::update(float deltaTime)
{
    GameObject::update(deltaTime);
    this->bounceOffScreenBounds();
    this->limitSpeed(MAX_SPEED);
}

void Ball::bounceOffScreenBounds()
{
    // Check if the ball has collided with the screen bounds
    if (position.x - collider->radius < -400 && rigidBody->linearVelocity.x < 0)
    {
        // Ball hit the left screen bound, reverse the x velocity
        rigidBody->linearVelocity.x = -rigidBody->linearVelocity.x;
    }
    else if (position.x + collider->radius > 400 && rigidBody->linearVelocity.x > 0)
    {
        // Ball hit the right screen bound, reverse the x velocity
        rigidBody->linearVelocity.x = -rigidBody->linearVelocity.x;
    }

    if (position.y - collider->radius < -248 && rigidBody->linearVelocity.y < 0)
    {
        // Ball hit the top screen bound, reverse the y velocity
        rigidBody->linearVelocity.y = -rigidBody->linearVelocity.y;
    }
    else if (position.y + collider->radius > 248 && rigidBody->linearVelocity.y > 0)
    {
        // Ball hit the bottom screen bound, reverse the y velocity
        rigidBody->linearVelocity.y = -rigidBody->linearVelocity.y;
    }
}

void Ball::limitSpeed(float maxSpeed)
{
    if (this->rigidBody->linearVelocity.Magnitude() > maxSpeed)
    {
        this->rigidBody->linearVelocity = this->rigidBody->linearVelocity.Normalized() * maxSpeed;
    }
}
