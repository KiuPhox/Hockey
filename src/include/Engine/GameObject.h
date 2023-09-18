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
    std::string name = "";

    Vector2 position;
    Vector2 scale = Vector2(1, 1);
    float angle = 0;

    GameObject(Vector2 p_pos);

    virtual void update(float deltaTime);
    virtual void onCollision(GameObject *other);
    virtual void onTrigger(GameObject *other);

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
