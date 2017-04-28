#include "StartSceneManager.hpp"

StartSceneManager::StartSceneManager(sf::RenderWindow* _renderWindow)
{
    renderWindow = _renderWindow;
    scene = new StartScene();
}

void StartSceneManager::drawScene()
{
    scene->draw(renderWindow);
}
