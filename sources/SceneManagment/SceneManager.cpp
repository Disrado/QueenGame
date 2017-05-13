#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow *_renderWindow, tgui::Gui *_gui)
{
    renderWindow = _renderWindow;
    gui = _gui;
    playScene = nullptr;
    previousScene = nullptr;
    
    currentScene = this->createScene(Scenes::Start);
    currentSceneType = Scenes::Start;
}

SceneManager::~SceneManager()
{
    delete currentScene;
}

Scene* SceneManager::createScene(Scenes _sceneType)
{
    switch (_sceneType) {
    case Scenes::Start:
        return (Scene*)new StartScene(renderWindow->getSize(), gui, this);
        break;

    case Scenes::Play:
        playScene = new PlayScene(renderWindow->getSize(), gui, this);
        return (Scene*)playScene;
        break;

    case Scenes::Settings:
        return (Scene*)new SettingsScene(renderWindow->getSize(), gui, this);
        break;

    case Scenes::Pause:
        return (Scene*)new PauseScene(renderWindow->getSize(), gui, this);
        break;

    default:
        return nullptr;
    }
}

void SceneManager::replaceCurrentScene(Scenes _newScene)
{
    switch(_newScene) {
    case::Scenes::Start:
        break;
        
    case::Scenes::Play:
        break;
        
    case::Scenes::Settings:
        break;
        
    case::Scenes::Pause:
        break;
    }
}

void SceneManager::backToPreviousScene()
{
    
}

PlayScene* SceneManager::getPlayScene()
{
    return playScene;
}
    
void SceneManager::drawScene()
{
    currentScene->draw(renderWindow);
}
