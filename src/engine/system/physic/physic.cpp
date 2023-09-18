#include "Engine/Physic.h"
#include "Engine/GameObject.h"

#include "Engine/RigidBody.h"
#include "Engine/Collisions.h"

#include <iostream>

Physic::Physic()
{
    this->bodies1 = std::vector<RigidBody *>();
    this->bodies2 = std::vector<RigidBody *>();
    this->collisions = std::vector<CollisionManifold>();
}

void Physic::update()
{
    this->bodies1.clear();
    this->bodies2.clear();
    this->collisions.clear();

    for (auto &collider : Collider::colliders)
    {
        for (auto &other : Collider::colliders)
        {
            if (collider == other)
                continue;

            CollisionManifold result = CollisionManifold();
            RigidBody *rb1 = collider->gameObject->getComponent<RigidBody>();
            RigidBody *rb2 = other->gameObject->getComponent<RigidBody>();

            if (rb1 != nullptr && rb2 != nullptr && rb1->mass != 0 && rb2->mass != 0)
            {
                result = Collisions::findCollisionFeatures(collider, other);
            }

            if (result.isColliding)
            {
                bodies1.push_back(rb1);
                bodies2.push_back(rb2);
                collider->gameObject->onCollision(other->gameObject);
                other->gameObject->onCollision(collider->gameObject);
                collisions.push_back(result);
            }

            for (int k = 0; k < this->impulseIterations; k++)
            {
                for (int i = 0; i < collisions.size(); i++)
                {
                    int jSize = collisions[i].getContactPoints().size();
                    for (int j = 0; j < jSize; j++)
                    {
                        RigidBody *rb1 = bodies1[i];
                        RigidBody *rb2 = bodies2[i];
                        this->applyImpulse(rb1, rb2, collisions[i]);
                    }
                }
            }
        }
    }
}

void Physic::applyImpulse(RigidBody *a, RigidBody *b, CollisionManifold &m)
{
    float invMass1 = a->inverseMass;
    float invMass2 = b->inverseMass;
    float invMassSum = invMass1 + invMass2;

    if (invMassSum == 0)
    {
        return;
    }

    Vector2 relativeVelocity = b->linearVelocity - a->linearVelocity;
    Vector2 relativeNormal = m.getNormal().Normalized();

    if (relativeVelocity.Dot(relativeNormal) > 0)
    {
        return;
    }

    float e = std::min(a->cor, b->cor);
    float numerator = -(1 + e) * relativeVelocity.Dot(relativeNormal);
    float j = numerator / invMassSum;

    if (m.getContactPoints().size() > 0 && j != 0)
    {
        j /= (float)m.getContactPoints().size();
    }

    Vector2 impulse = relativeNormal * j;

    if (a->isStatic)
    {
        b->linearVelocity = b->linearVelocity + impulse * invMass2;
    }
    else if (b->isStatic)
    {
        a->linearVelocity = a->linearVelocity - impulse * invMass1;
    }
    else
    {
        a->linearVelocity = a->linearVelocity - impulse * invMass1;
        b->linearVelocity = b->linearVelocity + impulse * invMass2;
    }
}