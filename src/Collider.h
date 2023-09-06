#include <vector>

#include "Vector2.h"
#include "GameObject.h"

class Collider
{
public:
    static std::vector<Collider *> colliders;
    GameObject *gameObject = nullptr;

    enum TYPE_COLLIDER
    {
        COLLIDER_RECT,
        COLLIDER_CIRCLE
    };

    TYPE_COLLIDER _type = COLLIDER_RECT;

    Vector2 size;
    Vector2 offset;
    float radius = 0;

    void update();

private:
    Collider(GameObject *obj);
    bool checkCollision(Collider *other);
};