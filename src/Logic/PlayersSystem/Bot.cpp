#include "../../include/Logic/PlayersSystem/Bot.hpp"

Bot::Bot(const std::string& _name, Queen* _queen, DifficultyLevel _level) : Player(_name, _queen)
{
    difficultyLevel = _level;
    finishTurn = true;
}

void Bot::setPositionForTurn(shared_ptr<Cell> _targetCell)
{
    finishTurn = false;
}

void Bot::turn()
{
    auto start = std::chrono::system_clock::now();
    
    auto availableCells = queen->getAvailableCells(queen->getPosition());

    switch(difficultyLevel) {
    case DifficultyLevel::Easy: {
        srand(time(NULL));
        cellForTurn = availableCells[rand() % availableCells.size()];
        break;
    }
    case DifficultyLevel::Medium: {
        auto comparator = [] (shared_ptr<Cell> first, shared_ptr<Cell> second) {
            return first->getWeight() < second->getWeight();
        };
        cellForTurn = *std::max_element(availableCells.begin(), availableCells.end(), comparator);
        break;
    }
    case DifficultyLevel::Hard: {
        int cellDiff = 0;     //difference between two cells weights
        int bestTempDiff = 0; //biggest difference between two cells weights in one loop
        int bestTurnDiff = 0; //in all turn
        cellForTurn = availableCells[0]; //if available cell count == 1
        vector<shared_ptr<Cell>> nextAvailableCells;
        
        for(auto cell : availableCells) {
            nextAvailableCells  = queen->getAvailableCells(cell->getCenterCoord());
            
            for(auto nextCell : nextAvailableCells) {
                auto nextnextAvailableCells  = queen->getAvailableCells(nextCell->getCenterCoord());

                for(auto nnextCell : nextAvailableCells)
                    cellDiff = cell->getWeight() - nnextCell->getWeight();
                if(cellDiff > bestTempDiff)
                    bestTempDiff = cellDiff;
            }
            
            if(bestTempDiff > bestTurnDiff) {
                bestTurnDiff = bestTempDiff;
                cellForTurn = cell;
            }
            
            break;
        }
    }
    }

    auto end = std::chrono::system_clock::now();
    std::this_thread::sleep_for((std::chrono::milliseconds(500) - (end - start)));
    
    queen->move(cellForTurn);
    score += queen->getConqueredPoints();
    
    finishTurn = true;
}          
