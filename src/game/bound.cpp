#include "Game/Bound.h"
#include "Engine/AABBCollider.h"
#include "Engine/RigidBody.h"

Bound::Bound(Vector2 pos, Vector2 size) : GameObject(pos)
{
    new AABBCollider(this, size);
    RigidBody *rb = new RigidBody(this);
    rb->cor = 2.5f;
    rb->isStatic = true;
}