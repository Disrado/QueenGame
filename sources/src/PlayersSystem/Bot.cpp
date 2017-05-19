#include "../../include/PlayersSystem/Bot.hpp"

Bot::Bot(const std::string& _name) : Player(_name)
{
    hardLevel = Settings::getInstance().getDifficultyLevel();
}

void Bot::turn(const sf::Vector2f& _newPosition, Board* _board)
{// _new Position is ignored
    int bestTempDiff = 0; //Biggest difference between two cells weights in one loop
    int bestTurnDiff = 0; //in all turn
    sf::Vector2f newPosition = sf::Vector2f();
    auto availableCells = _board->getAvailableCells(_board->getQueenPosition());

    if(availableCells.size() == 1)
        newPosition = availableCells[0]->getCenterCoord();
    else
        for(auto cell : availableCells) {
            auto nextAvailableCells = _board->getAvailableCells(cell->getCenterCoord());
            
            for(auto nextCell : nextAvailableCells) {
                int cellDiff = cell->getWeight() - nextCell->getWeight();
                if(cellDiff > bestTempDiff)
                    bestTempDiff = cellDiff;
            }

            if(bestTurnDiff < bestTempDiff) {
                bestTurnDiff = bestTempDiff;
                newPosition = cell->getCenterCoord();
            }
        }
    
    _board->moveQueen(newPosition);
    score += _board->getQueenPoints();
}
