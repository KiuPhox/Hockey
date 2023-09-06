#include "Player.h"
#include "GameObject.h"

Player::Player(Vector2 p_pos, SDL_Texture *p_tex, TEAM team) : GameObject(p_pos, p_tex)
{
    this->team = team;
    this->angle = (team == RED_TEAM) ? 90 : -90;
}

void Player::update(double deltaTime)
{
}
