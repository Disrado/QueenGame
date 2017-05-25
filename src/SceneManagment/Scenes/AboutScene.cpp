#include "../../../include/SceneManagment/Scenes/AboutScene.hpp"

AboutScene::AboutScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr)  : Scene(_smgr, _gui)
{
    background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("chess_background")));

    createLabels(_windowSize);
    createBackBtn(_windowSize);
}

AboutScene::~AboutScene()
{
    gui->remove(backBtn);
}

void AboutScene::createLabels(const sf::Vector2u &_windowSize)
{
    DeveloperEMailLbl = new sf::Text("Developer E-mail: " + DEVELOPER_EMAIL,
                                     *(ResourceManager::getInstance().getFont("Kurale")));
    DeveloperEMailLbl->setCharacterSize(_windowSize.y / 20);
    DeveloperEMailLbl->setOutlineThickness(3.0);
    DeveloperEMailLbl->setFillColor(sf::Color::Black);
    DeveloperEMailLbl->setOutlineColor(sf::Color::Red);
    DeveloperEMailLbl->setPosition(_windowSize.x / 2 - DeveloperEMailLbl->getLocalBounds().width / 2,
                                   _windowSize.y / 2 - _windowSize.y / 13);

    projectLinkLbl = new sf::Text("Project link: " + PROJECT_LINK,
                                  *(ResourceManager::getInstance().getFont("Kurale")));
    projectLinkLbl->setCharacterSize(_windowSize.y / 20);
    projectLinkLbl->setOutlineThickness(3.0);
    projectLinkLbl->setFillColor(sf::Color::Black);
    projectLinkLbl->setOutlineColor(sf::Color::Red);
    projectLinkLbl->setPosition(_windowSize.x / 2 - projectLinkLbl->getLocalBounds().width / 2,
                                _windowSize.y / 2 + _windowSize.y / 13);
}
void AboutScene::createBackBtn(const sf::Vector2u &_windowSize)
{
    backBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    backBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    backBtn->setPosition(backBtn->getSize().x * 0.5, _windowSize.y - backBtn->getSize().y * 2);
    backBtn->setText("Back");
    backBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(backBtn);
}

void AboutScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    _renderWindow->draw(*DeveloperEMailLbl);
    _renderWindow->draw(*projectLinkLbl);
    gui->draw();
}

