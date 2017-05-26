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

void MusicPlayer::reset()
{
	playList[currentTrack]->setPlayingOffset(sf::Time::Zero);
}

void MusicPlayer::update()
{
    if(Settings::getInstance().isMusicEnabled() && currentState == State::Playing) {
        if(playList[currentTrack]->getStatus() != sf::SoundSource::Status::Playing) {
            playList[currentTrack]->play();
            if(playList[currentTrack]->getStatus() != sf::SoundSource::Status::Playing) {
                if (currentTrack < playList.size() - 1) {
                    playList[currentTrack]->setPlayingOffset(sf::Time::Zero);
                    playList[++currentTrack]->play();
                } else {
                    playList[currentTrack]->setPlayingOffset(sf::Time::Zero);
                    currentTrack = 0;
                    playList[++currentTrack]->play();
                }
            }
        }
    } else {
        playList[currentTrack]->pause();
    }
    
    playList[0]->setVolume(Settings::getInstance().getMusicVolume());
}
