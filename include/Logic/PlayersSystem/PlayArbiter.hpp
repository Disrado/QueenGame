#ifndef PLAYARBITER_HPP
#define PLAYARBITER_HPP

#include "../../SceneManagment/SceneManager.hpp"
#include "../../GameSystem/Settings.hpp"
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
    CurrentTurn currentTurn;
    std::string winnerName;
    int winnerScore;
    SceneManager* smgr;
    Queen* queen;
    
public:
    PlayArbiter(SceneManager* _smgr, Queen* _queen);
    ~PlayArbiter();
    int getFirstPlayerScore() const;
    int getSecondPlayerScore() const;
    const std::string& getWinnerName() const;
    int getWinnerScore() const;
    void update();
    void turn(const sf::Vector2f& _mousePosition);
};

#endif //PLAYARBITER_HPP
