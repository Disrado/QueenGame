#ifndef MUSIC_PLAYER_HPP
#define MUSIC_PLAYER_HPP

#include <SFML/Audio.hpp>
#include "ResourceManager.hpp"
#include "Settings.hpp"
#include <vector>
#include <memory>

enum State { Playing, Paused };

class MusicPlayer
{
private:
    std::vector<std::shared_ptr<sf::Music>> playList;
    unsigned int currentTrack;
    State currentState;
        
    MusicPlayer();
    ~MusicPlayer() {}
        
public:
    static MusicPlayer& getInstance();

    MusicPlayer(const MusicPlayer&) = delete;
    MusicPlayer& operator=(const MusicPlayer&) = delete;

    void play();
    void pause();
	void reset();
    
    void update();
};

#endif //MUSIC_PLAYER_HPP
