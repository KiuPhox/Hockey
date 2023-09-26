#include "Game/Game.h"

#include "Engine/RigidBody.h"

std::vector<Player *> Game::redPlayers;
std::vector<Player *> Game::bluePlayers;
Ball *Game::ball;
int Game::activeRedIndex = 0;
int Game::activeBlueIndex = 0;

void Game::changeActivePlayer(Player::TEAM team)
{
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

void Game::reset()
{
    redPlayers[0]->position = Vector2(-150, 0);
    redPlayers[0]->angle = 0;
    bluePlayers[0]->position = Vector2(150, 0);
    bluePlayers[0]->angle = 180;
    ball->position = Vector2(0, 0);
    ball->getComponent<RigidBody>()->linearVelocity = Vector2(0, 0);
}