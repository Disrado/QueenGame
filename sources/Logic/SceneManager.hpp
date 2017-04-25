#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "../Scenes/PlaySceneManager.hpp"
#include "../Scenes/StartSceneManager.hpp"

enum Scenes { play, start, settings };

class StartSceneManager;

class SceneManager
{
private:
    PlaySceneManager *playSceneMngr;
    StartSceneManager *startSceneMngr;
    Scenes currentScene;
    sf::RenderWindow* renderWindow;
        
public:
    SceneManager(sf::RenderWindow *_renderWindow);
    ~SceneManager();
    void handleMouseClick(sf::Vector2i& _mousePosition);
    void drawScene();
    void setCurrentScene(Scenes _newScene);
};

#endif //SCENEMANAGER_HPP
