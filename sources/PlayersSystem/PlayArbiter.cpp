#include "PlayArbiter.hpp"

PlayArbiter::PlayArbiter(SceneManager* _smgr)
{
    smgr = _smgr;
    
    if(Settings::getInstance().getOpponentType() == OpponentType::bot) {
        firstPlayer = new Player(_smgr);
        bot = new Bot(_smgr);
    } else {
        firstPlayer = new Player(_smgr);
        secondPlayer = new Player(_smgr);
    }

    currentTurn = CurrentTurn::FirstPlayer;
}

PlayArbiter::~PlayArbiter()
{
    delete firstPlayer;

    if(secondPlayer)
        delete secondPlayer;

    if(bot)
        delete bot;
}

int PlayArbiter::getFirstPlayerScore()
{
    return firstPlayer->getScore();
}

int PlayArbiter::getSecondPlayerScore()
{
    if(Settings::getInstance().getOpponentType() == OpponentType::bot)
        return bot->getScore();
    else
        return secondPlayer->getScore();
}

void PlayArbiter::turn(const sf::Vector2i& _mousePosition)
{
    if(currentTurn == CurrentTurn::FirstPlayer) {
        firstPlayer->turn(_mousePosition);
        currentTurn = CurrentTurn::SecondPlayer;
    } else {
        if(Settings::getInstance().getOpponentType() == OpponentType::bot)
            bot->turn(_mousePosition);
        else
            secondPlayer->turn(_mousePosition);

        currentTurn = CurrentTurn::FirstPlayer;
    }

    smgr->getPlayScene()->setFirstPlayerScore(firstPlayer->getScore());
    smgr->getPlayScene()->setSecondPlayerScore(secondPlayer->getScore());
}
