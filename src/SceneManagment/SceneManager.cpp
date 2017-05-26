#include "../../include/SceneManagment/SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow *_renderWindow, tgui::Gui *_gui)
{
    renderWindow = _renderWindow;
    gui = _gui;
    playScene = nullptr;
    
    currentScene = this->createScene(Scenes::Start);
    currentSceneType = Scenes::Start;
}

shared_ptr<Scene> SceneManager::createScene(Scenes _sceneType)
{
    switch (_sceneType) {
    case Scenes::Start:
		if (currentSceneType == Scenes::Pause)
			playScene.reset();
        return shared_ptr<Scene>((Scene*)new StartScene(renderWindow->getSize(), gui, this));
        break;
    case Scenes::PrePlay:
        return shared_ptr<Scene>((Scene*)new PrePlayScene(renderWindow->getSize(), gui, this));
        break;
    case Scenes::Settings:
        return shared_ptr<Scene>((Scene*)new SettingsScene(renderWindow->getSize(), gui, this));
        break;
    case Scenes::About:
        return shared_ptr<Scene>((Scene*)new AboutScene(renderWindow->getSize(), gui, this));
        break;
    case Scenes::Play:
        playScene = shared_ptr<PlayScene>(new PlayScene(renderWindow->getSize(), gui, this));
        return (shared_ptr<Scene>)playScene;
        break;
    case Scenes::Pause:
        return shared_ptr<Scene>((Scene*)new PauseScene(renderWindow, gui, this));
        break;
    case Scenes::End:
        return shared_ptr<Scene>((Scene*)new EndScene(renderWindow->getSize(), gui, this,
                                    playScene->getPlayArbiter()->getWinnerName(),
                                    playScene->getPlayArbiter()->getWinnerScore()));
        break;
    }
}

void SceneManager::replaceCurrentScene(Scenes _newScene)
{
    switch(_newScene) {
    case::Scenes::Start:
            currentScene = std::move(this->createScene(Scenes::Start));
        break;

    case::Scenes::PrePlay:
        currentScene = std::move(this->createScene(Scenes::PrePlay));
        break;

    case::Scenes::Settings:
        currentScene = std::move(this->createScene(Scenes::Settings));
        break;
        
    case::Scenes::About:
        currentScene = std::move(this->createScene(Scenes::About));
        break;
        
    case::Scenes::Play:
        if(currentSceneType == Scenes::Pause) {
            currentScene = playScene;
            playScene->unhideGui();
        } else {
            currentScene = std::move(this->createScene(Scenes::Play));
        }
        break;

    case::Scenes::Pause:
        if(currentSceneType == Scenes::Pause || currentSceneType != Scenes::Play)
            break;
        else {
            playScene->hideGui();
            currentScene = std::move(this->createScene(Scenes::Pause));
        }
        break;

    case::Scenes::End:
        currentScene = std::move(this->createScene(Scenes::End));
		playScene.reset();
        currentSceneType = Scenes::End;
        break;
    }

    currentSceneType = _newScene;
}

Scenes SceneManager::getCurrentSceneType()
{
    return currentSceneType ;
}

PlayScene* SceneManager::getPlayScene()
{
    return playScene.get();
}

void SceneManager::updateCurrentScene()
{
    if(currentSceneType == Scenes::Play)
        playScene->update();
}
    
void SceneManager::drawScene()
{
    currentScene->draw(renderWindow);
}
