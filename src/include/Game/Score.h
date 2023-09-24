#include "Player.h"
#include "Engine/Text.h"

class Score
{
public:
    static void init(TTF_Font *font);
    static void increase(Player::TEAM team);
    static void reset();

private:
    static int redScore;
    static int blueScore;

    static Text *redScoreText;
    static Text *blueScoreText;
};