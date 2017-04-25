#include "StartSceneManager.hpp"

StartSceneManager::StartSceneManager(sf::RenderWindow* _renderWindow)
{
    renderWindow = _renderWindow;
    scene = new StartScene();
}

void StartSceneManager::checkClickPosition(SceneManager* _smgr)
{
    _smgr->setCurrentScene(Scenes::play);
}

void StartSceneManager::drawScene()
{
    scene->draw(renderWindow);
}
