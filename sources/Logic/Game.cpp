#include "Game.hpp"

Game::Game()
{
    app_window = new sf::RenderWindow(sf::VideoMode(1920, 1080),
                                      "QueenGame",
                                      sf::Style::Fullscreen);		
    
    playScene = new PlayScene(app_window);
    eventHandler = new EventHandler(playScene->getBoard(), playScene->getQueen());
}

Game::~Game()
{
    delete app_window;
    delete eventHandler;
    delete playScene;
}

void Game::startLoop()
{
    playScene->createBackGround();
    
    while (app_window->isOpen()) {
        
        sf::Event event;
        while (app_window->pollEvent(event))
            if (event.type == sf::Event::Closed)
                app_window->close();
	
        app_window->clear();
        eventHandler->HandleMouseActions();
        playScene->draw(app_window);
        app_window->display();
    }    
}
