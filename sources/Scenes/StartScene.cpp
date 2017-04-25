#include "StartScene.hpp"

StartScene::StartScene()
{
    background = new sf::Sprite(*(TextureLoader::Instance().getItem("blue_background")));
}

void StartScene::draw(sf::RenderWindow* _renderWindow)
{
    _renderWindow->draw(*background);
}
