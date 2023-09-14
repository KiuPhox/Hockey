#include "Game/Player.h"
#include "Engine/Collider.h"

Player::Player(Vector2 p_pos, SDL_Texture *p_tex, TEAM team) : GameObject(p_pos, p_tex)
{
    this->name = "player";
    this->team = team;
    this->angle = (team == RED_TEAM) ? 90 : -90;
    new Collider(this);
}

void Player::update(double deltaTime)
{
}
