#include "PlaySceneManager.hpp"

PlaySceneManager::PlaySceneManager(sf::RenderWindow* _renderWindow)
{
    renderWindow = _renderWindow;
    auto windowSize = renderWindow->getSize();
    pscene = new PlayScene(windowSize);
    hightlightPossibleMoves();
}

PlaySceneManager::~PlaySceneManager()
{
    delete pscene;
}

bool PlaySceneManager::moveQueen(sf::Vector2i _newPosition)
{
    auto cellsArray = pscene->getCells();
    
    for(auto &line : cellsArray)
        for(auto &cell : line)
            if(cell->checkBelongs(_newPosition))
                if(pscene->getQueen()->canMove(cell)) {
                    pscene->getQueen()->move(cell);
                    return true;
                }
    
    return false;
}

void PlaySceneManager::hightlightPossibleMoves()
{
    auto cellsArray = pscene->getCells();
    
    for(auto &line : cellsArray)
        for(auto &cell : line)
            if(pscene->getQueen()->canMove(cell))
                cell->showFrame();
            else
                cell->disableFrame();
}

void PlaySceneManager::drawScene()
{
    pscene->draw(renderWindow);
}
