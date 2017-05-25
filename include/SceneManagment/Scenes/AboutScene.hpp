#ifndef ABOUTSCENE_HPP
#define ABOUTSCENE_HPP

#include <TGUI/TGUI.hpp>
#include <string>
#include "../SceneManager.hpp"
#include "Scene.hpp"

class SceneManager;

const std::string DEVELOPER_EMAIL = "n.maltsev.dis@gmail.com";
const std::string PROJECT_LINK = "https://github.com/Disrado/QueenGame";

class AboutScene : public Scene
{
private:
    sf::Text* DeveloperEMailLbl;
    sf::Text* projectLinkLbl;
    std::shared_ptr<tgui::Button> backBtn;

    void createLabels(const sf::Vector2u& _windowSize);
    void createBackBtn(const sf::Vector2u& _windowSize);
    
public:
    AboutScene(const sf::Vector2u& _windowSize, tgui::Gui* _gui, SceneManager* _smgr);
    ~AboutScene();
    void draw(sf::RenderWindow* _renderWindow) override;
};


#endif //ABOUTSCENE_HPP
