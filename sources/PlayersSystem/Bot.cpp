#include "Bot.hpp"

Bot::Bot(SceneManager* _smgr)
{
    smgr = _smgr;
    score = 0;
    level = Settings::getInstance().getDifficultyLevel();
}

int Bot::getScore()
{
    return score;
}

void Bot::turn(const sf::Vector2i& _newPosition)
{
    score += smgr->getPlayScene()->moveQueen(_newPosition);
}
