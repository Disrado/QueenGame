#include "../../../include/Logic/PlayersSystem/Bot.hpp"

Bot::Bot(const std::string& _name) : Player(_name)
{
    hardLevel = Settings::getInstance().getDifficultyLevel();
}

void Bot::setPositionForTurn(const sf::Vector2f& _mousePosition, Queen* _queen)
{
    int bestTempDiff = 0; //Biggest difference between two cells weights in one loop
    int bestTurnDiff = 0; //in all turn
    Cell* cellToMove = nullptr;
    auto availableCells = _queen->getAvailableCells(_queen->getPosition());

    // TODO: if "draw" - show score
    // TODO: поюзать умные указатели в getAvailablecells
    
    if(availableCells.size() == 1)
        cellToMove = availableCells[0];
    else
        for(auto cell : availableCells) {
            auto nextAvailableCells = _queen->getAvailableCells(cell->getCenterCoord());

            for(auto nextCell : nextAvailableCells) {
                int cellDiff = cell->getWeight() - nextCell->getWeight();
                if(cellDiff > bestTempDiff)
                    bestTempDiff = cellDiff;
            }

            if(bestTurnDiff < bestTempDiff) {
                bestTurnDiff = bestTempDiff;
                cellToMove = cell;
            }
        }
    
    positionForTurn = cellToMove->getCenterCoord();
    finishTurn = false;
}

void Bot::turn(Board* _board, Queen* _queen)
{
   if(finishTurn)
        return;

   std::this_thread::sleep_for(400ms);

   _queen->move(_board->getCellByCoord(positionForTurn));
    score += _queen->getConqueredPoints();
    
    finishTurn = true;
}
