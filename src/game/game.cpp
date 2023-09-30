#include <iostream>

#include "Game/Game.h"

#include "Engine/RigidBody.h"

std::vector<Player *> Game::redPlayers;
std::vector<Player *> Game::bluePlayers;
Ball *Game::ball;
int Game::activeRedIndex = 0;
int Game::activeBlueIndex = 0;

void Game::changeActivePlayer(Player::TEAM team)
{
    std::cout << activeRedIndex;
    if (team == Player::RED_TEAM)
    {
        redPlayers[activeRedIndex]->active = false;
        activeRedIndex = (activeRedIndex + 1) % redPlayers.size();
        redPlayers[activeRedIndex]->active = true;
    }
    else
    {
        bluePlayers[activeBlueIndex]->active = false;
        activeBlueIndex = (activeBlueIndex + 1) % bluePlayers.size();
        bluePlayers[activeBlueIndex]->active = true;
    }
}

Player *Game::getActivePlayer(Player::TEAM team)
{
    if (team == Player::RED_TEAM)
    {
        return redPlayers[activeRedIndex];
    }
    else
    {
        return bluePlayers[activeBlueIndex];
    }
}

void Game::reset()
{
    redPlayers[0]->position = Vector2(-150, 0);
    redPlayers[1]->position = Vector2(-250, 100);
    redPlayers[2]->position = Vector2(-250, -100);

    for (int i = 0; i < redPlayers.size(); i++)
    {
        redPlayers[i]->active = (i == 0);
        redPlayers[i]->angle = 0;
    }

    activeRedIndex = 0;

    bluePlayers[0]->position = Vector2(150, 0);
    bluePlayers[1]->position = Vector2(250, -100);
    bluePlayers[2]->position = Vector2(250, 100);

    for (int i = 0; i < bluePlayers.size(); i++)
    {
        bluePlayers[i]->active = (i == 0);
        bluePlayers[i]->angle = 180;
    }

    activeBlueIndex = 0;

    ball->position = Vector2(0, 0);
    ball->getComponent<RigidBody>()->linearVelocity = Vector2(0, 0);
}