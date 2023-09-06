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
    GameObject *getGameObject() { return gameObject; }
    void update();

private:
    TYPE_COLLIDER _type = COLLIDER_RECT;

    GameObject *gameObject = nullptr;

    Collider(GameObject *obj);
};