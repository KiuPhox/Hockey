#include "Game/Arrow.h"
#include "Game/Game.h"

#include "Engine/AssetPreload.h"
#include "Engine/GameObject.h"
#include "Engine/Sprite.h"

Arrow::Arrow(Vector2 pos, Player::TEAM team) : GameObject(pos)
{
    this->scale = Vector2(0.2f, 0.2f);
    this->team = team;

    ImageKey imageKey = team == Player::TEAM::RED_TEAM ? ImageKey::RED_ARROW : ImageKey::BLUE_ARROW;
    new Sprite(this, AssetPreload::getTexture(imageKey));
}

void Arrow::update(float deltaTime)
{
    GameObject::update(deltaTime);
    this->position = Game::getActivePlayer(this->team)->position + Vector2(0, 50);
}