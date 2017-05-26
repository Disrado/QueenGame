#include "../../../include/SceneManagment/Scenes/PauseScene.hpp"

PauseScene::PauseScene(const sf::RenderWindow* _renderWindow, tgui::Gui* _gui, SceneManager* _smgr) : Scene(_smgr, _gui)
{
	auto windowCapture = ResourceManager::getInstance().createVoidTexture("PauseSceneBackground");
    windowCapture->loadFromImage(_renderWindow->capture());
    background = new sf::Sprite(*windowCapture);
    background->setColor(sf::Color(254, 254, 254, 50));

	background = new sf::Sprite(*(ResourceManager::getInstance().getTexture("PauseSceneBackground")));
	background->setScale(_renderWindow->getSize().x / background->getLocalBounds().width,
		_renderWindow->getSize().y / background->getLocalBounds().height);

    createResumeBtn(_renderWindow->getSize());
    createExitBtn(_renderWindow->getSize());
    MusicPlayer::getInstance().pause();
}

PauseScene::~PauseScene()
{
	MusicPlayer::getInstance().play();
    gui->remove(resumeBtn);
    gui->remove(exitBtn);
}

void PauseScene::createResumeBtn(const sf::Vector2u& _windowSize)
{
    resumeBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    resumeBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    resumeBtn->setPosition((_windowSize.x / 2) - (resumeBtn->getSize().x / 2),
                           (_windowSize.y / 2) - resumeBtn->getSize().y * 0.75);
    resumeBtn->setText("Resume");
    resumeBtn->connect("mousereleased",
                       [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Play); });
    gui->add(resumeBtn);
}

void PauseScene::createExitBtn(const sf::Vector2u& _windowSize)
{
    exitBtn = ResourceManager::getInstance().getGuiTheme()->load("Button");
    exitBtn->setSize(_windowSize.x / 10, _windowSize.y / 13);
    exitBtn->setPosition((_windowSize.x / 2) - (exitBtn->getSize().x / 2),
                         (_windowSize.y / 2) + exitBtn->getSize().y * 0.75);
    exitBtn->setText("Exit");
    exitBtn->connect("mousereleased", [_smgr = smgr](){ _smgr->replaceCurrentScene(Scenes::Start); });
    gui->add(exitBtn);
}

void PauseScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
    gui->draw();
}
