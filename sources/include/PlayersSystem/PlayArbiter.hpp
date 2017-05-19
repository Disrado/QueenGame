#ifndef PLAYARBITER_HPP
#define PLAYARBITER_HPP

#include "../SceneManagment/SceneManager.hpp"
#include "../GameSystem/Settings.hpp"
#include "Player.hpp"
#include "Bot.hpp"

class PlayScene;

enum CurrentTurn { FirstPlayer, SecondPlayer };

class PlayArbiter
{
private:
    Player* firstPlayer;
    Player* secondPlayer;
    OpponentType opponentType;
    SceneManager* smgr;
    CurrentTurn currentTurn;
    std::string winnerName;
    int winnerScore;
    
public:
    PlayArbiter(SceneManager* _smgr);
    ~PlayArbiter();
    int getFirstPlayerScore() const;
    int getSecondPlayerScore() const;
    const std::string& getWinnerName() const;
    int getWinnerScore() const;
    void turn(const sf::Vector2f& _mousePosition);
};

#endif //PLAYARBITER_HPP
