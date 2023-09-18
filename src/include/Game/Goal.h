#pragma once

#include "Engine/GameObject.h"
#include "Game/Player.h"

class Goal : public GameObject
{
public:
    Player::TEAM team;

    Goal(Vector2 pos, Player::TEAM team);

    void onTrigger(GameObject *other) override;
};