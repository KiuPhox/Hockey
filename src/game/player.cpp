#include "Game/Player.h"
#include "Engine/Collider.h"
#include "Engine/Input.h"
#include "Engine/GameMath.h"

#include <iostream>

const float MOVE_SPEED = 200;
const float ROTATE_SPEED = 20;

Player::Player(Vector2 p_pos, SDL_Texture *p_tex, TEAM team) : GameObject(p_pos, p_tex)
{
    this->name = "player";
    this->team = team;
    this->angle = (team == RED_TEAM) ? 0 : 180;
    this->active = true;

    Collider *collider = new Collider(this, Collider::COLLIDER_CIRCLE);
    collider->radius = 36;
}

void Player::update(float deltaTime)
{
    GameObject::update(deltaTime);

    Vector2 movementVector = this->getMovementVector();
    this->velocity = movementVector * MOVE_SPEED;
    this->position += velocity * deltaTime;
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
    }
    return move;
}

void Player::setActive(bool active)
{
    this->active = active;
}
