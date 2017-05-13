#include "Game.hpp"

Game::Game()
{
    appWindow = new sf::RenderWindow({1920, 1080},
                                     "QueenGame",
                                     sf::Style::Fullscreen);		

    gui = new tgui::Gui(*appWindow);  

    ResourceManager::getInstance().loadTexturesFromDirectory(PATH_TO_PICTURES);
    ResourceManager::getInstance().loadFontsFromDirectory(PATH_TO_FONTS);
    
     smgr = new SceneManager(appWindow, gui);
     arbiter = new PlayArbiter(smgr);
     eventHandler = new EventHandler(smgr, arbiter);
}

Game::~Game()
{
    delete appWindow;
    delete gui;
    delete eventHandler;
    delete smgr;
    delete arbiter;
}

void Game::startLoop()
{
    sf::Event event;
    while (appWindow->isOpen()) {
        
        while (appWindow->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                appWindow->close();

            gui->handleEvent(event);
            eventHandler->HandleUserActions(event);
        }
	
        appWindow->clear();
        smgr->drawScene();
        appWindow->display();
    }    
}
