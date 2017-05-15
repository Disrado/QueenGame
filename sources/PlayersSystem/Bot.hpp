#ifndef BOT_HPP
#define BOT_HPP

#include "../GameSystem/Settings.hpp"
#include "Player.hpp"

class Bot : public Player
{
private:
    DifficultyLevel hardLevel;
    
public:
    Bot();
    void turn(const sf::Vector2i& _newPosition,  Board* _board) override;
};

#endif //BOT_HPP
