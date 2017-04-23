#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow *_renderWindow)
{
    playSceneMngr = new PlaySceneManager(_renderWindow);
    currentScene = Scenes::play;
    renderWindow = _renderWindow;
}

void SceneManager::setCurrentScene(Scenes _newScene)
{
    currentScene = _newScene;
}

void SceneManager::handleMouseClick(sf::Vector2i& _mousePosition)
{
    if(playSceneMngr->moveQueen(_mousePosition))
        playSceneMngr->hightlightPossibleMoves(); 
}

void SceneManager::drawScene()
{
    // switch (currentScene) {

    // case Scenes::play:
    playSceneMngr->drawScene();
    // }
}
