#pragma once

#include "Game/Player.h"
#include "Engine/GameObject.h"

class Arrow : public GameObject
{
public:
    Arrow(Vector2 pos, Player::TEAM team);
    void update(float deltaTime) override;

private:
    Player::TEAM team;
};