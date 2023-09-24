#include "Game/Score.h"

int Score::redScore;
int Score::blueScore;

Text *Score::redScoreText;
Text *Score::blueScoreText;

void Score::init(TTF_Font *font)
{
    redScore = 0;
    blueScore = 0;

    GameObject *redScoreObj = new GameObject(Vector2(-25, 225));
    GameObject *blueScoreObj = new GameObject(Vector2(27, 225));

    redScoreText = new Text(redScoreObj, "0", font, {186, 90, 90, 255}, Align::CENTER);
    blueScoreText = new Text(blueScoreObj, "0", font, {72, 114, 155, 255}, Align::CENTER);
}

void Score::increase(Player::TEAM team)
{
    if (team == Player::RED_TEAM)
    {
        redScore++;
        redScoreText->text = std::to_string(redScore);
    }
    else
    {
        blueScore++;
        blueScoreText->text = std::to_string(blueScore);
    }
}

void Score::reset()
{
    redScore = 0;
    blueScore = 0;
    redScoreText->text = std::to_string(redScore);
    blueScoreText->text = std::to_string(blueScore);
}
