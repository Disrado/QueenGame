#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../GameObjects/Board.hpp"
#include "../../GameObjects/Queen.hpp"

class Player
{
protected:
    int score;
    bool finishTurn;
    std::string name;
    shared_ptr<Cell> cellForTurn;
    Queen* queen;

public:
    Player(const std::string& _name, Queen* _queen);
    virtual ~Player() { }
    
    int getScore() const;
    const std::string& getName() const;
    
    bool isFinishTurn() const;
    virtual void setPositionForTurn(shared_ptr<Cell> _targetCell);
    virtual void turn();
};

#endif //PLAYER_HPP
