#ifndef BOT_HPP
#define BOT_HPP

#include <vector>
#include <thread>
#include <chrono>
#include "../../GameSystem/Settings.hpp"
#include "../../GameObjects/Board.hpp"
#include "Player.hpp"

class Bot : public Player
{
private:
    DifficultyLevel hardLevel;
    
public:
    Bot(const std::string& _name);
    //The first parameter is ignored, but it is needed
    void setPositionForTurn(const sf::Vector2f& _mousePosition, Queen* _queen) override;
    void turn(Board* _board, Queen* queen) override;
};

#endif //BOT_HPP
