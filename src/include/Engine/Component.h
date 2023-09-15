#pragma once

class GameObject;

class Component
{
public:
    GameObject *gameObject = nullptr;
    Component(GameObject *obj);

    virtual void update(float deltaTime);
};