#include "Game/Game.h"

static std::vector<Player> redPlayers;
static std::vector<Player> bluePlayers;

static unsigned int redPlayerActiveIndex;
static unsigned int bluePlayerActiveIndex;

static Ball ball;

static void init()
{
    GameObject *bg = new GameObject(Vector2(0, 0));
    new Sprite(bg, bgTexture);
    new Ball(Vector2(0, 0), ballTexture);
    new Player(Vector2(-150, 0), playerRedTexture, Player::RED_TEAM);
    new Player(Vector2(150, 0), playerBlueTexture, Player::BLUE_TEAM);

    // Screen
    new Bound(Vector2(-400, 0), Vector2(0, 496));
    new Bound(Vector2(400, 0), Vector2(0, 496));
    new Bound(Vector2(0, -248), Vector2(800, 0));
    new Bound(Vector2(0, 248), Vector2(800, 0));

    // Left goal bounds
    new Bound(Vector2(-390, 0), Vector2(12, 270));
    new Bound(Vector2(-353, -125), Vector2(56, 12));
    new Bound(Vector2(-353, 130), Vector2(56, 12));

    // Right goal bounds
    new Bound(Vector2(390, 0), Vector2(12, 270));
    new Bound(Vector2(353, -125), Vector2(56, 12));
    new Bound(Vector2(353, 130), Vector2(56, 12));

    // Goals
    new Goal(Vector2(-364, 0), Player::RED_TEAM);
    new Goal(Vector2(364, 0), Player::BLUE_TEAM);

    Score::init(font32);
}
