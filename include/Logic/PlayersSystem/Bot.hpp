#ifndef BOT_HPP
#define BOT_HPP

#include <vector>
#include <chrono>
#include <algorithm>
#include "../../GameSystem/Settings.hpp"
#include "Player.hpp"

class Bot : public Player
{
private:
    DifficultyLevel difficultyLevel;
    
public:
    Bot(const std::string& _name, Queen* _queen, DifficultyLevel _level);
    //The first parameter is ignored, but it is needed
    void setPositionForTurn(shared_ptr<Cell> _targetCell) override;
    void turn() override;
};

#endif //BOT_HPP
