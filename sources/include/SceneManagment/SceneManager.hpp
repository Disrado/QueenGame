#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <memory>
#include "Scenes/SettingsScene.hpp"
#include "Scenes/PrePlayScene.hpp"
#include "Scenes/PauseScene.hpp"
#include "Scenes/StartScene.hpp" 
#include "Scenes/PlayScene.hpp"
#include "Scenes/EndScene.hpp"
#include "Scenes/Scene.hpp"

class SettingsScene;
class PrePlayScene;
class StartScene;
class PauseScene;
class PlayScene;
class EndScene;
class Scene;

enum Scenes { Play, Start, Settings, Pause, PrePlay, End };

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
    Scenes getCurrentSceneType();
    PlayScene* getPlayScene(); //because playscene live longer and need to other classes
    void replaceCurrentScene(Scenes _newScene);
    void updateSettingsScene(); //calling after change resolution on settings scene
    void drawScene();
};

#endif //SCENEMANAGER_HPP
