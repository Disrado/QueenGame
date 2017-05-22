#ifndef BOT_HPP
#define BOT_HPP

#include <vector>
#include "../GameSystem/Settings.hpp"
#include "../GameObjects/Board.hpp"
#include "Player.hpp"

class Bot : public Player
{
private:
    DifficultyLevel hardLevel;
    
public:
    Bot(const std::string& _name);
    //The first parameter is ignored, but it is needed
    void turn(const sf::Vector2f& _newPosition, Board* _board) override;
};

#endif //BOT_HPP
