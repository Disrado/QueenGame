#include "PlayArbiter.hpp"

PlayArbiter::PlayArbiter(PlayScene* _playScene)
{
    playScene = _playScene;
    
    firstPlayer = new Player();
    
    if(Settings::getInstance().getOpponentType() == OpponentType::player)
        secondPlayer = new Player();
    else
        secondPlayer = new Bot();

    currentTurn = CurrentTurn::FirstPlayer;
}

PlayArbiter::~PlayArbiter()
{
    delete firstPlayer;
    delete secondPlayer;
}

int PlayArbiter::getFirstPlayerScore()
{
    return firstPlayer->getScore();
}

int PlayArbiter::getSecondPlayerScore()
{
    return secondPlayer->getScore();
}

void PlayArbiter::turn(const sf::Vector2i& _mousePosition)
{
    if(currentTurn == CurrentTurn::FirstPlayer) {
        firstPlayer->turn(_mousePosition, playScene->getBoard());
        currentTurn = CurrentTurn::SecondPlayer;
    } else {
        secondPlayer->turn(_mousePosition, playScene->getBoard());
        currentTurn = CurrentTurn::FirstPlayer;
    } 

    playScene->setFirstPlayerScore(firstPlayer->getScore());
    playScene->setSecondPlayerScore(secondPlayer->getScore());
}
