#include "../../include/Logic/PlayersSystem/Player.hpp"

Player::Player(const std::string& _name, Queen* _queen)
{
    queen = _queen;
    score = 0;
    name = _name;
    finishTurn = true;
    cellForTurn = nullptr;
}

const std::string& Player::getName() const
{
    return name;
}

int Player::getScore() const
{
    return score;
}

bool Player::isFinishTurn() const
{
    return finishTurn;
}

void Player::setPositionForTurn(shared_ptr<Cell> _targetCell)
{
    cellForTurn = _targetCell;
    finishTurn = false;
}

void Player::turn()
{
    queen->move(cellForTurn);
    score += queen->getConqueredPoints();
    finishTurn = true;
}
