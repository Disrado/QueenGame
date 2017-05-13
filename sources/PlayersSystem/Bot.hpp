#ifndef BOT_HPP
#define BOT_HPP

#include "../SceneManagment/SceneManager.hpp"
#include "../GameSystem/Settings.hpp"

class Bot
{
private:
    DifficultyLevel level;
    int score;
    SceneManager* smgr;
    
public:
    Bot(SceneManager* _smgr);    
    int getScore();
    void turn(const sf::Vector2i& _newPosition);
};

#endif //BOT_HPP
