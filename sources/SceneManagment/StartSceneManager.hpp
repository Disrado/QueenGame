#ifndef STARTSCENEMANAGER_HPP
#define STARTSCENEMANAGER_HPP

#include "../Scenes/StartScene.hpp"

class StartSceneManager
{
private:
    StartScene* scene;
    sf::RenderWindow* renderWindow;
    
public:
    StartSceneManager(sf::RenderWindow* _renderWindow);
    void drawScene();
};

#endif //STARTSCENEMANAGER_HPP
