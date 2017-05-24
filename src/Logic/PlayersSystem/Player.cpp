#include "../../../include/Logic/PlayersSystem/Player.hpp"

Player::Player(const std::string& _name)
{
    name = _name;
    score = 0;
    finishTurn = true;
    positionForTurn = sf::Vector2f();
}

bool Player::makeTurn() const
{
    return finishTurn;
}

void Player::setPositionForTurn(const sf::Vector2f& _mousePosition, Queen* _queen)
{
    positionForTurn = _mousePosition;
    finishTurn = false;
}

const std::string& Player::getName() const
{
    return name;
}

int Player::getScore() const
{
    return score;
}

void Player::turn(Board* _board, Queen* _queen)
{
    if(finishTurn)
        return;
    
    _queen->move(_board->getCellByCoord(positionForTurn));
    score += _queen->getConqueredPoints();

    positionForTurn = sf::Vector2f();
    finishTurn = true;
}
