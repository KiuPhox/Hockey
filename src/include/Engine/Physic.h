#pragma once

#include "Collider.h"

class Physic
{
public:
    Physic();
    void update(double deltaTime);

private:
    bool checkCollision(Collider *collider1, Collider *collider2, double deltaTime);
};