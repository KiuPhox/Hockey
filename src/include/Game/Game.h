#pragma once

#include <vector>

#include "Game/Ball.h"
#include "Game/Player.h"

class Game
{
public:
    static std::vector<Player *> redPlayers;
    static std::vector<Player *> bluePlayers;
    static Ball *ball;

    static void init();
    static void update(float deltaTime);
    static void reset();

private:
    static unsigned int redPlayerActiveIndex;
    static unsigned int bluePlayerActiveIndex;

    static void changeActivePlayer(Player::TEAM team);
};