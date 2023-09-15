#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Engine/GameObject.h"

std::vector<GameObject *> GameObject::gameObjects;

GameObject::GameObject(Vector2 p_pos, SDL_Texture *p_tex) : position(p_pos), tex(p_tex)
{
    gameObjects.push_back(this);

    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;
    SDL_QueryTexture(p_tex, NULL, NULL, &rect.w, &rect.h);
}

void GameObject::update(double deltaTime)
{
    for (auto &component : components)
    {
        component->update(deltaTime);
    }
}

void GameObject::onCollision(GameObject *other)
{
}

void GameObject::addComponent(Component *component)
{

    components.push_back(component);
}

template <typename T>
T *GameObject::getComponent()
{
    for (auto &component : components)
    {
        T *result = dynamic_cast<T *>(component);
        if (result != nullptr)
            return result;
    }
    return nullptr;
}