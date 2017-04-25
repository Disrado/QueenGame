#ifndef STARTSCENEMANAGER_HPP
#define STARTSCENEMANAGER_HPP

#include "../Logic/SceneManager.hpp"
#include "StartScene.hpp"

class SceneManager;

class StartSceneManager
{
private:
    StartScene* scene;
    sf::RenderWindow* renderWindow;
    
public:
    StartSceneManager(sf::RenderWindow* _renderWindow);
    void checkClickPosition(SceneManager* _smgr);
    void drawScene();
    
};

#endif //STARTSCENEMANAGER_HPP
