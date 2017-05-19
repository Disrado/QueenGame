#include "../../include/PlayersSystem/Player.hpp"

Player::Player(const std::string& _name)
{
    name = _name;
    score = 0;
}

const std::string& Player::getName() const
{
    return name;
}

int Player::getScore() const
{
    return score;
}

void Player::turn(const sf::Vector2f& _newPosition,  Board* _board)
{
    _board->moveQueen(_newPosition);
    score += _board->getQueenPoints();
}
