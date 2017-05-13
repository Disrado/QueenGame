#ifndef PLAYARBITER_HPP
#define PLAYARBITER_HPP

#include "../GameSystem/Settings.hpp"
#include "Player.hpp"
#include "Bot.hpp"

enum CurrentTurn { FirstPlayer, SecondPlayer };

class PlayArbiter
{
private:
    Player* firstPlayer;
    Player* secondPlayer;
    Bot* bot;
    SceneManager* smgr;
    CurrentTurn currentTurn;
    
public:
    PlayArbiter(SceneManager* _smgr);
    ~PlayArbiter();
    int getFirstPlayerScore();
    int getSecondPlayerScore();
    void turn(const sf::Vector2i& _mousePosition);
};

#endif //PLAYARBITER_HPP
