#include "../../include/PlayersSystem/PlayArbiter.hpp"

PlayArbiter::PlayArbiter(SceneManager* _smgr)
{
    smgr = _smgr;
    opponentType = Settings::getInstance().getOpponentType();
    
    firstPlayer = new Player("Player 1");
    
    if(opponentType == OpponentType::player)
        secondPlayer = new Player("Player 2");
    else
        secondPlayer = new Bot("Bot");

    currentTurn = CurrentTurn::FirstPlayer;

    winnerName = "";
    winnerScore = 0;
}

PlayArbiter::~PlayArbiter()
{
    delete firstPlayer;
    delete secondPlayer;
}

int PlayArbiter::getFirstPlayerScore() const
{
    return firstPlayer->getScore();
}

int PlayArbiter::getSecondPlayerScore() const
{
    return secondPlayer->getScore();
}

const std::string& PlayArbiter::getWinnerName() const
{
    return winnerName;
}

int PlayArbiter::getWinnerScore() const
{
    return winnerScore;
}

void PlayArbiter::turn(const sf::Vector2f& _mousePosition)
{
    if(!smgr->getPlayScene()->getBoard()->queenCanMove(_mousePosition))
        return;
    
    Board* board = smgr->getPlayScene()->getBoard();
    
    if(opponentType == OpponentType::bot) {
        firstPlayer->turn(_mousePosition, board);
        secondPlayer->turn(_mousePosition, board);
    } else {
        if(currentTurn == CurrentTurn::FirstPlayer) {
            firstPlayer->turn(_mousePosition, board);
            currentTurn = CurrentTurn::SecondPlayer;
        } else {
            secondPlayer->turn(_mousePosition, board);
            currentTurn = CurrentTurn::FirstPlayer;
        }
    }

    smgr->getPlayScene()->setSecondPlayerScore(secondPlayer->getScore());
    smgr->getPlayScene()->setFirstPlayerScore(firstPlayer->getScore());

    // if(board->getAvailableCellCount() == 0) {
    //     if(firstPlayer->getScore() > secondPlayer->getScore()) {
    //         winnerName = firstPlayer->getName();
    //         winnerScore = firstPlayer->getScore();
    //     } else if(firstPlayer->getScore() < secondPlayer->getScore()) {
    //         winnerName = secondPlayer->getName();
    //         winnerScore = secondPlayer->getScore();
    //     }
        
    //     smgr->replaceCurrentScene(Scenes::End);
    // }
}
