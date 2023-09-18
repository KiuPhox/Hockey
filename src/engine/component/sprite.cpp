#include "Engine/Sprite.h"

Sprite::Sprite(GameObject *obj, SDL_Texture *texture) : Component(obj)
{
    this->texture = texture;
    this->rect = {0, 0, 0, 0};
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
}