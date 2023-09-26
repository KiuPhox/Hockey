#include "Game/Goal.h"
#include "Game/Score.h"
#include "Game/Game.h"

#include "Engine/GameObject.h"
#include "Engine/AABBCollider.h"

#include <iostream>

Goal::Goal(Vector2 pos, Player::TEAM team) : GameObject(pos)
{
    this->team = team;
    AABBCollider *collider = new AABBCollider(this, Vector2(30, 250));
    collider->isTrigger = true;
    new RigidBody(this);
}

void Goal::onTrigger(GameObject *other)
{
    if (other->name == "ball")
    {
        if (this->team == Player::RED_TEAM)
        {
            Score::increase(Player::BLUE_TEAM);
        }
        else
        {
            Score::increase(Player::RED_TEAM);
        }
        Game::reset();
    }
}