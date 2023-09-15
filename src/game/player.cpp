#include "Game/Player.h"
#include "Engine/Collider.h"
#include "Engine/Input.h"

#include <iostream>

const float SPEED = 200;

Player::Player(Vector2 p_pos, SDL_Texture *p_tex, TEAM team) : GameObject(p_pos, p_tex)
{
    this->name = "player";
    this->team = team;
    this->angle = (team == RED_TEAM) ? 90 : -90;
    this->active = true;
    new Collider(this, Collider::COLLIDER_CIRCLE);
}

void Player::update(float deltaTime)
{
    GameObject::update(deltaTime);

    Vector2 movement = this->getMovementVector();

    this->position += movement * SPEED * deltaTime;
}

Vector2 Player::getMovementVector()
{
    if (this->active)
    {
        if (this->team == RED_TEAM)
        {
            if (Input::getKey(SDL_SCANCODE_W))
                return Vector2(0, -1);
            if (Input::getKey(SDL_SCANCODE_S))
                return Vector2(0, 1);
            if (Input::getKey(SDL_SCANCODE_A))
                return Vector2(-1, 0);
            if (Input::getKey(SDL_SCANCODE_D))
                return Vector2(1, 0);
        }
    }
}

void Player::setActive(bool active)
{
    this->active = active;
}
