#include "Bot.hpp"

Bot::Bot() : Player()
{
    hardLevel = Settings::getInstance().getDifficultyLevel();
}

void Bot::turn(const sf::Vector2i& _newPosition,  Board* _board)
{
    
    
    score += _board->moveQueen(_newPosition);
}
