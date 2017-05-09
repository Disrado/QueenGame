#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "../Scenes/PlayScene.hpp"
#include "../Scenes/StartScene.hpp"

class StartScene;
class PlayScene;

enum Scenes { play, start, settings };

class SceneManager
{
private:
    sf::RenderWindow* renderWindow;
    tgui::Gui* gui;
    StartScene* startScene;
    PlayScene* playScene;
    Scenes currentScene;
        
public:
    SceneManager(sf::RenderWindow *_renderWindow, tgui::Gui *_gui);
    ~SceneManager();
    
    void setCurrentScene(Scenes _newScene);

    PlayScene* getPlayScene();
    Scenes getCurrentScene();

    void drawScene();
};

#endif //SCENEMANAGER_HPP
