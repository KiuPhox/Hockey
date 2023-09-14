#include "Engine/Component.h"
#include "Engine/GameObject.h"

Component::Component(GameObject *obj)
{
    this->gameObject = obj;
    this->gameObject->addComponent(this);
}

void Component::update(double deltaTime)
{
    //
}