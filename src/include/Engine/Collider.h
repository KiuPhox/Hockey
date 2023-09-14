#pragma once
#include <vector>

#include "Vector2.h"
#include "Component.h"

class Collider : public Component
{
public:
    static std::vector<Collider *> colliders;

    enum TYPE_COLLIDER
    {
        COLLIDER_RECT,
        COLLIDER_CIRCLE
    };

    TYPE_COLLIDER type = COLLIDER_RECT;

    Collider(GameObject *obj, TYPE_COLLIDER type = COLLIDER_RECT);

    Vector2 size;
    Vector2 offset;
    float radius = 0;

    void update(double deltaTime) override;

private:
    bool checkCollision(Collider *other);
};