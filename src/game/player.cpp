#include "Game/Player.h"
#include "Engine/CircleCollider.h"
#include "Engine/Input.h"
#include "Engine/GameMath.h"
#include "Engine/Sprite.h"

#include <iostream>

const float MOVE_SPEED = 200;
const float ROTATE_SPEED = 20;

Player::Player(Vector2 p_pos, SDL_Texture *p_tex, TEAM team) : GameObject(p_pos)
{
    this->name = "player";
    this->team = team;
    this->angle = (team == RED_TEAM) ? 0 : 180;
    this->active = true;

    new Sprite(this, p_tex);

    collider = new CircleCollider(this, 32);

    this->rigidBody = new RigidBody(this);
    this->rigidBody->cor = 5;
}

void Player::update(float deltaTime)
{
    GameObject::update(deltaTime);
    this->move(deltaTime);
}

void Player::move(float deltaTime)
{
    Vector2 movementVector = this->getMovementVector();
    this->rigidBody->linearVelocity = movementVector * MOVE_SPEED;

    if (!(movementVector == Vector2::ZERO))
    {
        this->angle = Math::LerpAngle(this->angle, movementVector.GetAngle(), ROTATE_SPEED * deltaTime);
    }
}

Vector2 Player::getMovementVector()
{
    Vector2 move = Vector2(0, 0);
    if (this->active)
    {
        if (this->team == RED_TEAM)
        {
            if (Input::getKey(SDL_SCANCODE_W))
                move.y = -1;
            if (Input::getKey(SDL_SCANCODE_S))
                move.y = 1;
            if (Input::getKey(SDL_SCANCODE_A))
                move.x = -1;
            if (Input::getKey(SDL_SCANCODE_D))
                move.x = 1;
        }
        else
        {
            // Arrow keys
            if (Input::getKey(SDL_SCANCODE_UP))
                move.y = -1;
            if (Input::getKey(SDL_SCANCODE_DOWN))
                move.y = 1;
            if (Input::getKey(SDL_SCANCODE_LEFT))
                move.x = -1;
            if (Input::getKey(SDL_SCANCODE_RIGHT))
                move.x = 1;
        }
    }
    return move.Normalized();
}

void Player::setActive(bool active)
{
    this->active = active;
}
