#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow *_renderWindow, tgui::Gui *_gui)
{
    renderWindow = _renderWindow;
    gui = _gui;
    
    playScene = new PlayScene(_renderWindow->getSize(), _gui);
    startScene = new StartScene(_renderWindow->getSize(), _gui, this);
    
    currentScene = Scenes::start;
}

SceneManager::~SceneManager()
{
    delete playScene;
    delete startScene;
}

void SceneManager::setCurrentScene(Scenes _newScene)
{
    currentScene = _newScene;
}

Scenes SceneManager::getCurrentScene()
{
    return currentScene;
}

PlayScene* SceneManager::getPlayScene()
{
    return playScene;
}

void SceneManager::drawScene()
{
    switch (currentScene) {
        
    case Scenes::play:
        playScene->draw(renderWindow);
        break;

    case Scenes::start:
        startScene->draw(renderWindow);
        break;
    }
}
