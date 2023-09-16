#include <iostream>

#include "Game/Ball.h"
#include "Engine/GameMath.h"

const float BOUNCE_FACTOR = 100;
const float MAX_SPEED = 2000;

Ball::Ball(Vector2 p_pos, SDL_Texture *p_tex) : GameObject(p_pos, p_tex)
{
    this->name = "ball";

    this->collider = new Collider(this, Collider::COLLIDER_CIRCLE);
    this->collider->radius = 20;

    this->rigidBody = new RigidBody(this);
    this->rigidBody->friction = 0.999f;
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
    if (position.x - collider->radius < -400 && rigidBody->velocity.x < 0)
    {
        // Ball hit the left screen bound, reverse the x velocity
        rigidBody->velocity.x = -rigidBody->velocity.x;
    }
    else if (position.x + collider->radius > 400 && rigidBody->velocity.x > 0)
    {
        // Ball hit the right screen bound, reverse the x velocity
        rigidBody->velocity.x = -rigidBody->velocity.x;
    }

    if (position.y - collider->radius < -248 && rigidBody->velocity.y < 0)
    {
        // Ball hit the top screen bound, reverse the y velocity
        rigidBody->velocity.y = -rigidBody->velocity.y;
    }
    else if (position.y + collider->radius > 248 && rigidBody->velocity.y > 0)
    {
        // Ball hit the bottom screen bound, reverse the y velocity
        rigidBody->velocity.y = -rigidBody->velocity.y;
    }
}

void Ball::limitSpeed(float maxSpeed)
{
    if (this->rigidBody->velocity.Magnitude() > maxSpeed)
    {
        this->rigidBody->velocity = this->rigidBody->velocity.Normalized() * maxSpeed;
    }
}

void Ball::onCollision(GameObject *other)
{
    if (other->name == "player")
    {
        RigidBody *playerRb = other->getComponent<RigidBody>();

        // Make the ball bounce off the player
        Vector2 collisionNormal = this->position - other->position;
        collisionNormal = collisionNormal.Normalized();

        // Calculate the relative velocity of the ball and the player along the collision normal
        Vector2 relativeVelocity = this->rigidBody->velocity - playerRb->velocity;
        float relativeSpeed = collisionNormal.Dot(relativeVelocity);

        // Calculate the impulse for the bounce
        float impulse = -(1.0f + BOUNCE_FACTOR) * relativeSpeed;

        // Update the ball's velocity to simulate the bounce
        this->rigidBody->velocity += collisionNormal * impulse / 36;
    }
}