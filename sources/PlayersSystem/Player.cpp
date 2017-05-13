#include "Player.hpp"

Player::Player(SceneManager* _smgr)
{
    smgr = _smgr;
    score = 0;
}

int Player::getScore()
{
    return score;
}

void Player::turn(const sf::Vector2i& _newPosition)
{
    score += smgr->getPlayScene()->moveQueen(_newPosition);
}
