#include "../../include/Logic/Game.hpp"

Game::Game()
{
    renderWindow = new sf::RenderWindow({0, 0},
                                        "QueenGame",
                                        sf::Style::Fullscreen);
    renderWindow->setSize(renderWindow->getSize());

    gui = new tgui::Gui(*renderWindow);

    ResourceManager::getInstance().loadTexturesFromDirectory(PATH_TO_PICTURES);
    ResourceManager::getInstance().loadFontsFromDirectory(PATH_TO_FONTS);
    ResourceManager::getInstance().loadMusicFromDirectory(PATH_TO_MUSIC);
    ResourceManager::getInstance().loadGuiTheme(PATH_TO_GUI_THEME);
        
    smgr = new SceneManager(renderWindow, gui);
    eventHandler = new EventHandler(smgr);
}

Game::~Game()
{
    delete eventHandler;
    delete smgr;
    delete gui;
    delete renderWindow;
}

void Game::start()
{
    sf::Event event;
    while (renderWindow->isOpen()) {
        while (renderWindow->pollEvent (event)) {
            if (event.type == sf::Event::Closed)
                renderWindow->close();

            gui->handleEvent(event);
            eventHandler->HandleUserActions(event);
        }

        renderWindow->clear();
        smgr->updateCurrentScene();
        MusicPlayer::getInstance().update();
        smgr->drawScene();
        renderWindow->display();
    }
}
