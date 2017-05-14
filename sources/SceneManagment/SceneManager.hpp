#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <memory>
#include "Scenes/PlayScene.hpp"
#include "Scenes/StartScene.hpp"
#include "Scenes/PauseScene.hpp"
#include "Scenes/SettingsScene.hpp"

class SettingsScene;
class StartScene;
class PauseScene;
class PlayScene;

enum Scenes { Play, Start, Settings, Pause };

class SceneManager
{
private:
    sf::RenderWindow* renderWindow;
    tgui::Gui* gui;
    PlayScene* playScene;
    Scene* currentScene;
    Scenes currentSceneType;

private:
    Scene* createScene(Scenes _sceneType);
    
public:
    SceneManager(sf::RenderWindow *_renderWindow, tgui::Gui *_gui);
    
    PlayScene* getPlayScene();
    void replaceCurrentScene(Scenes _newScene);
    void drawScene();
};

#endif //SCENEMANAGER_HPP
