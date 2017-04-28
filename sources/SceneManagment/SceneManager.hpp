#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "PlaySceneManager.hpp"
#include "StartSceneManager.hpp"

enum Scenes { play, start, settings };

class SceneManager
{
private:
    sf::RenderWindow* renderWindow;
    StartSceneManager* startSmgr;
    PlaySceneManager* playSmgr;
    Scenes currentScene;
        
public:
    SceneManager(sf::RenderWindow *_renderWindow);
    ~SceneManager();
    
    void setCurrentScene(Scenes _newScene);

    Scenes getCurrentScene();
    //SettingsSceneManager getSettingsSceneManager();
    StartSceneManager* getStartSceneManager();
    PlaySceneManager* getPlaySceneManager();

    void drawScene();
};

#endif //SCENEMANAGER_HPP
