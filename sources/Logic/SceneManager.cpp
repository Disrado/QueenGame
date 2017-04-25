#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow *_renderWindow)
{
    playSceneMngr = new PlaySceneManager(_renderWindow);
    startSceneMngr = new StartSceneManager(_renderWindow);
    currentScene = Scenes::start;
    renderWindow = _renderWindow;
}

SceneManager::~SceneManager()
{
    delete playSceneMngr;
    delete startSceneMngr;
}

void SceneManager::setCurrentScene(Scenes _newScene)
{
    currentScene = _newScene;
}

void SceneManager::handleMouseClick(sf::Vector2i& _mousePosition)
{
    switch (currentScene) {
        
    case Scenes::play:
        if(playSceneMngr->moveQueen(_mousePosition))
            playSceneMngr->hightlightPossibleMoves();
        break;
        
    case Scenes::start:
        startSceneMngr->checkClickPosition(this);
        break;
    }
}

void SceneManager::drawScene()
{
    switch (currentScene) {
        
    case Scenes::play:
        playSceneMngr->drawScene();
        break;

    case Scenes::start:
        startSceneMngr->drawScene();
        break;
    }
}
