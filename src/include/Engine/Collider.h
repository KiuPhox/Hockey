#include <vector>

#include "Vector2.h"
#include "GameObject.h"

class Collider
{
public:
    enum TYPE_COLLIDER
    {
        COLLIDER_RECT,
        COLLIDER_CIRCLE
    };

    static std::vector<Collider *> colliders;
    GameObject *gameObject = nullptr;
    TYPE_COLLIDER _type = COLLIDER_RECT;

    Collider(GameObject *obj, TYPE_COLLIDER type = COLLIDER_RECT);

    Vector2 size;
    Vector2 offset;
    float radius = 0;

    void update();

private:
    bool checkCollision(Collider *other);
};