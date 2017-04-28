#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow *_renderWindow)
{
    playSmgr = new PlaySceneManager(_renderWindow);
    startSmgr = new StartSceneManager(_renderWindow);
    currentScene = Scenes::start;
    renderWindow = _renderWindow;
}

SceneManager::~SceneManager()
{
    delete playSmgr;
    delete startSmgr;
}

void SceneManager::setCurrentScene(Scenes _newScene)
{
    currentScene = _newScene;
}

Scenes SceneManager::getCurrentScene()
{
    return currentScene;
}    

StartSceneManager* SceneManager::getStartSceneManager()
{
    return startSmgr;
}

PlaySceneManager* SceneManager::getPlaySceneManager()
{
    return playSmgr;
}

void SceneManager::drawScene()
{
    switch (currentScene) {
        
    case Scenes::play:
        playSmgr->drawScene();
        break;

    case Scenes::start:
        startSmgr->drawScene();
        break;
    }
}
