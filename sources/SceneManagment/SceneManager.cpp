#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow *_renderWindow, tgui::Gui *_gui)
{
    renderWindow = _renderWindow;
    gui = _gui;
    
    currentScene = this->createScene(Scenes::start);
}

SceneManager::~SceneManager()
{
    delete currentScene;
}

Scene* SceneManager::createScene(Scenes _sceneType)
{
    switch (_sceneType) {
    case Scenes::start:
        return (Scene*)new StartScene(renderWindow->getSize(), gui, this);
        break;

    case Scenes::play:
        playScene = new PlayScene(renderWindow->getSize(), gui, this);
        return (Scene*)playScene;
        break;

    default:
        return nullptr;
    }
}

void SceneManager::replaceCurrentScene(Scenes _newScene)
{
    delete currentScene;
    currentScene = this->createScene(_newScene);
}

PlayScene* SceneManager::getPlayScene()
{
    return playScene;
}

void SceneManager::drawScene()
{
    currentScene->draw(renderWindow);
}
