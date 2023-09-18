#pragma once
#include <vector>

#include "Vector2.h"
#include "Component.h"

class Collider : public Component
{
public:
    static std::vector<Collider *> colliders;
    Vector2 offset = Vector2::ZERO;

    Collider(GameObject *obj);

    void update(float deltaTime) override;

private:
    bool checkCollision(Collider *other);
};