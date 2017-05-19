#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../GameObjects/Board.hpp"

class Player
{
protected:
    std::string name;
    int score;

public:
    Player(const std::string& _name);
    virtual ~Player() {}
    
    int getScore() const;
    const std::string& getName() const;
    
    virtual void turn(const sf::Vector2f& _newPosition, Board* _board);
};

#endif //PLAYER_HPP
