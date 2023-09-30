#pragma once

#include <vector>

#include "Player.h"
#include "Ball.h"

class Game
{
public:
    static std::vector<Player *> redPlayers;
    static std::vector<Player *> bluePlayers;
    static Ball *ball;

    static void changeActivePlayer(Player::TEAM team);
    static Player *getActivePlayer(Player::TEAM team);
    static void reset();

private:
    static int activeRedIndex;
    static int activeBlueIndex;
};