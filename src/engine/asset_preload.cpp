#include "Engine/AssetPreload.h"

std::map<ImageKey, SDL_Texture *> AssetPreload::textures;

void AssetPreload::init(RenderWindow *window)
{
    textures[BACKGROUND] = window->loadTexture("assets/images/bg.png");
    textures[BALL] = window->loadTexture("assets/images/ball.png");
    textures[RED_PLAYER] = window->loadTexture("assets/images/player_red.png");
    textures[BLUE_PLAYER] = window->loadTexture("assets/images/player_blue.png");
    textures[RED_ARROW] = window->loadTexture("assets/images/red_arrow.png");
    textures[BLUE_ARROW] = window->loadTexture("assets/images/blue_arrow.png");
}

SDL_Texture *AssetPreload::getTexture(ImageKey key)
{
    return textures[key];
}