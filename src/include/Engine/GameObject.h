#pragma once

#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

#include "Vector2.h"
#include "Engine/Component.h"

class GameObject
{
public:
    static std::vector<GameObject *> gameObjects;
    GameObject(Vector2 p_pos, SDL_Texture *p_tex);

    Vector2 position;
    Vector2 scale = Vector2(1, 1);

    float angle = 0;
    std::string name = "";

    SDL_Rect rect;
    SDL_Texture *tex;

    virtual void update(float deltaTime);
    virtual void onCollision(GameObject *other);

    void addComponent(Component *component);

    template <typename T>
    T *getComponent()
    {
        for (auto &component : components)
        {
            T *result = dynamic_cast<T *>(component);
            if (result != nullptr)
                return result;
        }
        return nullptr;
    }

private:
    std::vector<Component *> components;
};
