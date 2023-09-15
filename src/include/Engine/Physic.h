#pragma once

#include "Collider.h"

class Physic
{
public:
    Physic();
    void update();

private:
    bool checkCollision(Collider *collider1, Collider *collider2);
};