#ifndef PLAYARBITER_HPP
#define PLAYARBITER_HPP

#include "../SceneManagment/Scenes/PlayScene.hpp"
#include "../GameSystem/Settings.hpp"
#include "Player.hpp"
#include "Bot.hpp"

class PlayScene;

enum CurrentTurn { FirstPlayer, SecondPlayer };

class PlayArbiter
{
private:
    PlayScene* playScene;
    Player* firstPlayer;
    Player* secondPlayer;
    CurrentTurn currentTurn;
    
public:
    PlayArbiter(PlayScene* _playScene);
    ~PlayArbiter();
    int getFirstPlayerScore();
    int getSecondPlayerScore();
    void turn(const sf::Vector2i& _mousePosition);
};

#endif //PLAYARBITER_HPP
