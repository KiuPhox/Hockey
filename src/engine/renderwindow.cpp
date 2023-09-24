#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "SDL2/SDL2_gfxPrimitives.h"

#include "Engine/RenderWindow.h"
#include "Engine/CircleCollider.h"
#include "Engine/AABBCollider.h"

RenderWindow::RenderWindow(const char *title, int w, int h) : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderWindow::loadTexture(const char *filePath)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(GameObject *gameObject)
{
    Sprite *sprite = gameObject->getComponent<Sprite>();

    if (sprite != nullptr)
    {
        render(sprite);
    }

    Text *text = gameObject->getComponent<Text>();

    if (text != nullptr)
    {
        render(text);
    }

    // Debug collider
    Collider *collider = gameObject->getComponent<Collider>();

    if (collider != nullptr)
    {
        if (dynamic_cast<AABBCollider *>(collider) != nullptr)
        {
            AABBCollider *aabbCollider = dynamic_cast<AABBCollider *>(collider);
            SDL_Rect dst;
            dst.x = gameObject->position.x - aabbCollider->size.x * gameObject->scale.x / 2 + 400;
            dst.y = -gameObject->position.y - aabbCollider->size.y * gameObject->scale.y / 2 + 248;
            dst.w = aabbCollider->size.x * gameObject->scale.x;
            dst.h = aabbCollider->size.y * gameObject->scale.y;
            SDL_RenderDrawRect(renderer, &dst);
        }
        else if (dynamic_cast<CircleCollider *>(collider) != nullptr)
        {
            CircleCollider *circleCollider = dynamic_cast<CircleCollider *>(collider);
            circleColor(renderer, gameObject->position.x + circleCollider->offset.x + 400, -gameObject->position.y + circleCollider->offset.y + 248, circleCollider->radius, 0xFF0000FF);
        }
    }
}

void RenderWindow::render(Sprite *sprite)
{
    GameObject *gameObject = sprite->gameObject;

    SDL_Rect src;
    src.x = sprite->rect.x;
    src.y = sprite->rect.y;
    src.w = sprite->rect.w;
    src.h = sprite->rect.h;

    SDL_Rect dst;
    dst.x = gameObject->position.x - sprite->rect.w * gameObject->scale.x / 2 + 400;
    dst.y = -gameObject->position.y - sprite->rect.h * gameObject->scale.y / 2 + 248;
    dst.w = sprite->rect.w * gameObject->scale.x;
    dst.h = sprite->rect.h * gameObject->scale.y;

    SDL_RenderCopyEx(renderer, sprite->texture, &src, &dst, -gameObject->angle, 0, SDL_FLIP_NONE);
}

void RenderWindow::render(Text *text)
{
    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(text->font, text->text.c_str(), text->color);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    GameObject *gameObject = text->gameObject;

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.w = src.w;
    dst.h = src.h;

    switch (text->align)
    {
    case Align::LEFT:
        dst.x = gameObject->position.x + 400;
        dst.y = -gameObject->position.y + 248;
        break;
    case Align::CENTER:
        dst.x = gameObject->position.x + 400 - src.w / 2;
        dst.y = -gameObject->position.y + 248 - src.h / 2;
        break;
    case Align::RIGHT:
        dst.x = gameObject->position.x + 400 - src.w;
        dst.y = -gameObject->position.y + 248 - src.h;
        break;
    }

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}