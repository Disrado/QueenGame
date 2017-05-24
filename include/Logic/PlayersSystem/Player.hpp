#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../GameObjects/Board.hpp"
#include "../../GameObjects/Queen.hpp"

class Player
{
protected:
    std::string name;
    int score;
    bool finishTurn = false;
    sf::Vector2f positionForTurn;

public:
    Player(const std::string& _name);
    virtual ~Player() {}

    virtual void setPositionForTurn(const sf::Vector2f& _mousePosition, Queen* _queen);
    bool makeTurn() const;
    int getScore() const;
    const std::string& getName() const;
    
    virtual void turn(Board* _board, Queen* queen);
};

#endif //PLAYER_HPP
