#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../SceneManagment/SceneManager.hpp"

class Player
{
private:
    int score;
    SceneManager* smgr;

public:
    Player(SceneManager* _smgr);
    int getScore();    
    void turn(const sf::Vector2i& _newPosition);
};

#endif //PLAYER_HPP
