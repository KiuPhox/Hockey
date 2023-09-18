#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Engine/GameObject.h"

std::vector<GameObject *> GameObject::gameObjects;

GameObject::GameObject(Vector2 p_pos) : position(p_pos)
{
    gameObjects.push_back(this);
}

void GameObject::update(float deltaTime)
{
    for (auto &component : components)
    {
        component->update(deltaTime);
    }
}

void GameObject::onCollision(GameObject *other)
{
}

void GameObject::onTrigger(GameObject *other)
{
}

void GameObject::addComponent(Component *component)
{
    components.push_back(component);
}