#include "Game.hpp"

Game::Game()
{
    appWindow = new sf::RenderWindow(sf::VideoMode(1920, 1080),
                                      "QueenGame",
                                      sf::Style::Fullscreen);		

    TextureLoader::Instance().loadAllItemsFromDirectory(PATH_TO_PICTURES);
    
    smgr = new SceneManager(appWindow);
    eventHandler = new EventHandler(smgr);
}

Game::~Game()
{
    delete appWindow;
    delete eventHandler;
    delete smgr;
}

void Game::startLoop()
{
    sf::Event event;
    while (appWindow->isOpen()) {
        
        while (appWindow->pollEvent(event))
            if (event.type == sf::Event::Closed)
                appWindow->close();
	
        appWindow->clear();
        eventHandler->HandleMouseActions();
        smgr->drawScene();
        appWindow->display();
    }    
}
