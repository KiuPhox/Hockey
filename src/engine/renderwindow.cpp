#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "SDL2/SDL2_gfxPrimitives.h"

#include "Engine/RenderWindow.h"
#include "Engine/CircleCollider.h"
#include "Engine/AABBCollider.h"
#include "Engine/Sprite.h"

RenderWindow::RenderWindow(const char *p_title, int p_w, int p_h) : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture *RenderWindow::loadTexture(const char *p_filePath)
{
    SDL_Texture *texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

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

void RenderWindow::render(GameObject *p_gameObject)
{
    Sprite *sprite = p_gameObject->getComponent<Sprite>();

    if (sprite != nullptr)
    {
        SDL_Rect src;
        src.x = sprite->rect.x;
        src.y = sprite->rect.y;
        src.w = sprite->rect.w;
        src.h = sprite->rect.h;

        SDL_Rect dst;
        dst.x = p_gameObject->position.x - sprite->rect.w * p_gameObject->scale.x / 2 + 400;
        dst.y = p_gameObject->position.y - sprite->rect.h * p_gameObject->scale.y / 2 + 248;
        dst.w = sprite->rect.w * p_gameObject->scale.x;
        dst.h = sprite->rect.h * p_gameObject->scale.y;

        SDL_RenderCopyEx(renderer, sprite->texture, &src, &dst, p_gameObject->angle, 0, SDL_FLIP_NONE);
    }

    // Debug collider
    // Collider *collider = p_gameObject->getComponent<Collider>();

    // if (collider != nullptr)
    // {
    //     if (dynamic_cast<AABBCollider *>(collider) != nullptr)
    //     {
    //         AABBCollider *aabbCollider = dynamic_cast<AABBCollider *>(collider);
    //         SDL_Rect dst;
    //         dst.x = p_gameObject->position.x - aabbCollider->size.x * p_gameObject->scale.x / 2 + 400;
    //         dst.y = p_gameObject->position.y - aabbCollider->size.y * p_gameObject->scale.y / 2 + 248;
    //         dst.w = aabbCollider->size.x * p_gameObject->scale.x;
    //         dst.h = aabbCollider->size.y * p_gameObject->scale.y;
    //         SDL_RenderDrawRect(renderer, &dst);
    //     }
    //     else if (dynamic_cast<CircleCollider *>(collider) != nullptr)
    //     {
    //         CircleCollider *circleCollider = dynamic_cast<CircleCollider *>(collider);
    //         circleColor(renderer, p_gameObject->position.x + circleCollider->offset.x + 400, p_gameObject->position.y + circleCollider->offset.y + 248, circleCollider->radius, 0xFF0000FF);
    //     }
    // }
}

void RenderWindow::render(int x, int y, SDL_Texture *p_tex)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w;
    src.h;

    SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);

    SDL_Rect dst;
    dst.x = x + 400 - src.w / 2;
    dst.y = y + 248 - src.h / 2;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::render(float p_x, float p_y, const char *p_text, TTF_Font *font, SDL_Color textColor)
{
    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(font, p_text, textColor);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = p_x;
    dst.y = p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}

void RenderWindow::renderCenter(float p_x, float p_y, const char *p_text, TTF_Font *font, SDL_Color textColor)
{
    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(font, p_text, textColor);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = 800 / 2 - src.w / 2 + p_x;
    dst.y = 496 / 2 - src.h / 2 + p_y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}