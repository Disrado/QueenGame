#include "../../include/GameSystem/MusicPlayer.hpp"

MusicPlayer& MusicPlayer::getInstance()
{
    static MusicPlayer instance;
    return instance;
}

MusicPlayer::MusicPlayer()
{
    playList = ResourceManager::getInstance().getMusic();
    currentTrack = 0;
    currentState = State::Paused;
}

void MusicPlayer::play()
{
    currentState = State::Playing;
}

void MusicPlayer::pause()
{
    currentState = State::Paused;
}

void MusicPlayer::update()
{
    if(Settings::getInstance().isMusicEnabled() && currentState == State::Playing) {
        if(playList[0]->getStatus() != sf::SoundSource::Status::Playing) {
            playList[0]->play();
            if(playList[0]->getStatus() != sf::SoundSource::Status::Playing)
                playList[0]->setPlayingOffset(sf::Time::Zero);
        }
    } else {
        playList[0]->pause();
    }
    
    playList[0]->setVolume(Settings::getInstance().getMusicVolume());
}
