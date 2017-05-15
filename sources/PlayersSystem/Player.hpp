#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../GameObjects/Board.hpp"

class Player
{
protected:
    int score;

public:
    Player();
    virtual ~Player() {}
    int getScore();    
    virtual void turn(const sf::Vector2i& _newPosition, Board* _board);
};

#endif //PLAYER_HPP
