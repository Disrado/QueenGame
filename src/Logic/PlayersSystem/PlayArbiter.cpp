#include "../../../include/Logic/PlayersSystem/PlayArbiter.hpp"

PlayArbiter::PlayArbiter(SceneManager* _smgr, Queen* _queen)
{
    smgr = _smgr;
    queen = _queen;
    opponentType = Settings::getInstance().getOpponentType();
    
    firstPlayer = new Player("Player 1", _queen);
    
    if(opponentType == OpponentType::player)
        secondPlayer = new Player("Player 2", _queen);
    else
        secondPlayer = new Bot("Bot",
                               _queen,
                               Settings::getInstance().getDifficultyLevel());

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

void PlayArbiter::update()
{
    if(currentTurn == CurrentTurn::FirstPlayer) {
        if(!firstPlayer->isFinishTurn()) {
            firstPlayer->turn();
            currentTurn = CurrentTurn::SecondPlayer;
            smgr->getPlayScene()->setFirstPlayerScore(firstPlayer->getScore());
        }
<<<<<<< HEAD
    } else {
        if(!secondPlayer->isFinishTurn()) {
            secondPlayer->turn();
            currentTurn = CurrentTurn::FirstPlayer;
            smgr->getPlayScene()->setSecondPlayerScore(secondPlayer->getScore());
        }
    }
    
    smgr->getPlayScene()->hightlightCells();
=======
	} else {
		if (!secondPlayer->isFinishTurn()) {
			secondPlayer->turn();
			currentTurn = CurrentTurn::FirstPlayer;
			smgr->getPlayScene()->setSecondPlayerScore(secondPlayer->getScore());
		}
	}

	smgr->getPlayScene()->hightlightCells();
>>>>>>> 808447a9b081c61faabb3567e439cd7f8712bc93
    
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
        std::this_thread::sleep_for((std::chrono::milliseconds(500)));
        smgr->replaceCurrentScene(Scenes::End);
    }
}

void PlayArbiter::turn(const sf::Vector2f& _mousePosition)
{
    Board* board = smgr->getPlayScene()->getBoard();

<<<<<<< HEAD
    if(queen->canMove(board->getCellByCoord(_mousePosition), queen->getPosition())) {
=======
    if(queen->canMove(queen->getPosition(), board->getCellByCoord(_mousePosition)) &&
		firstPlayer->isFinishTurn() && secondPlayer->isFinishTurn()) {

>>>>>>> 808447a9b081c61faabb3567e439cd7f8712bc93
        shared_ptr<Cell> cellToMove = board->getCellByCoord(_mousePosition);
        
        if(opponentType == OpponentType::bot) {
            firstPlayer->setPositionForTurn(cellToMove);
            secondPlayer->setPositionForTurn(cellToMove);
        } else {
            if(currentTurn == CurrentTurn::FirstPlayer)
                firstPlayer->setPositionForTurn(cellToMove);
            else
                secondPlayer->setPositionForTurn(cellToMove);
        }
    }
}
