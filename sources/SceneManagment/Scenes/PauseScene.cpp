#include "PauseScene.hpp"

PauseScene::PauseScene(sf::RenderWindow* _renderWindow, tgui::Gui* _gui, SceneManager* _smgr)
{
    gui = _gui;

    auto texture = ResourceManager::getInstance().createVoidTexture("PauseSceneBackground");
    texture->loadFromImage(_renderWindow->capture());
    background = new sf::Sprite(*(texture.get()));
    background->setColor(sf::Color(254, 254, 254, 50));
    
    tgui::Theme::Ptr theme = tgui::Theme::create("../GUITheme/Black.txt");
    
    resumeBtn = theme->load("Button");
    resumeBtn->setSize(150, 50);
    resumeBtn->setPosition((_renderWindow->getSize().x / 2) - (resumeBtn->getSize().x / 2),
                           (_renderWindow->getSize().y / 2) - 40);
    resumeBtn->setText("Resume");
    resumeBtn->connect("mousereleased",[_smgr](){ _smgr->replaceCurrentScene(Scenes::Play); });
    gui->add(resumeBtn);

    exitBtn = theme->load("Button");
    exitBtn->setSize(150, 50);
    exitBtn->setPosition((_renderWindow->getSize().x / 2) - (exitBtn->getSize().x / 2),
                         (_renderWindow->getSize().y / 2) + 40);
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [=](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(exitBtn);
}

PauseScene::~PauseScene()
{
    ResourceManager::getInstance().removeTexture("PauseSceneBackground");
    gui->removeAllWidgets();
}

void PauseScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}
