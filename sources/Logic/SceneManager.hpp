#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "../Scenes/PlaySceneManager.hpp"

enum Scenes { play, start, settings };

class SceneManager
{
private:
    PlaySceneManager *playSceneMngr;
    Scenes currentScene;
    sf::RenderWindow* renderWindow;
        
public:
    SceneManager(sf::RenderWindow *_renderWindow);
    void handleMouseClick(sf::Vector2i& _mousePosition);
    void drawScene();
    void setCurrentScene(Scenes _newScene);
};

#endif //SCENEMANAGER_HPP
