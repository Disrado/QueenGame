#include "Player.hpp"

Player::Player()
{
    score = 0;
}

int Player::getScore()
{
    return score;
}

void Player::turn(const sf::Vector2i& _newPosition,  Board* _board)
{
    score += _board->moveQueen(_newPosition);
}
