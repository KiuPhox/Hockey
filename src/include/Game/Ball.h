#pragma once

#include <SDL2/SDL.h>
#include <vector>

#include "Engine/GameObject.h"
#include "Engine/Vector2.h"
#include "Engine/RigidBody.h"
#include "Engine/CircleCollider.h"
#include "Player.h"

class Ball : public GameObject
{
public:
    Ball(Vector2 p_pos, SDL_Texture *p_tex);
    void update(float deltaTime) override;

private:
    Vector2 velocity;
    RigidBody *rigidBody;
    CircleCollider *collider;

    void limitSpeed(float maxSpeed);
    void updateAngularVelocity();
};