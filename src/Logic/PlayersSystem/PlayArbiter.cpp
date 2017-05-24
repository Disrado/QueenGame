#include "../../../include/Logic/PlayersSystem/PlayArbiter.hpp"

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

void PlayArbiter::update(float _dTime)
{
    if(!smgr->getPlayScene()->getQueen()->isMoving()) {
        Queen* queen = smgr->getPlayScene()->getQueen();

        if(queen->getAvailableCellCount(queen->getPosition()) == 0) {
            if(firstPlayer->getScore() > secondPlayer->getScore()) {
                winnerName = firstPlayer->getName();
                winnerScore = firstPlayer->getScore();
            } else if(firstPlayer->getScore() < secondPlayer->getScore()) {
                winnerName = secondPlayer->getName();
                winnerScore = secondPlayer->getScore();
            } else {
                winnerName = "Draw";
                winnerScore = firstPlayer->getScore();
            }
            
            smgr->replaceCurrentScene(Scenes::End);
        }
        
        if(!firstPlayer->makeTurn())
            firstPlayer->turn(smgr->getPlayScene()->getBoard(), queen);

        if (!secondPlayer->makeTurn())
            secondPlayer->turn(smgr->getPlayScene()->getBoard(), queen);


    }
}

void PlayArbiter::turn(const sf::Vector2f& _mousePosition)
{ 
    Queen* queen = smgr->getPlayScene()->getQueen();

    if(!queen->canMove(queen->getPosition(), smgr->getPlayScene()->getBoard()->getCellByCoord(_mousePosition)))
        return;
  
    if(opponentType == OpponentType::bot) {
        firstPlayer->setPositionForTurn(_mousePosition, smgr->getPlayScene()->getQueen());
        secondPlayer->setPositionForTurn(_mousePosition, smgr->getPlayScene()->getQueen());
        // firstPlayer->turn(_mousePosition, board, queen);
        // secondPlayer->turn(_mousePosition, board, queen);
    } else {
        if(currentTurn == CurrentTurn::FirstPlayer) {
            firstPlayer->setPositionForTurn(_mousePosition, smgr->getPlayScene()->getQueen());
            currentTurn = CurrentTurn::SecondPlayer;
        } else {
            secondPlayer->setPositionForTurn(_mousePosition, smgr->getPlayScene()->getQueen());
            currentTurn = CurrentTurn::FirstPlayer;
        }
    }
}
