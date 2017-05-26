#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <BOOST/filesystem.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <TGUI/TGUI.hpp>
#include <vector>
#include <map>
#include <memory>
#include <string>

using namespace boost::filesystem;

class ResourceManager
{
private:
    std::map<std::string, std::shared_ptr<sf::Texture>> textures;
    std::map<std::string, std::shared_ptr<sf::Font>> fonts;
    std::vector<std::shared_ptr<sf::Music>> music;
    std::shared_ptr<tgui::Theme> guiTheme;
    
    ResourceManager() {}
    ~ResourceManager() {}
    std::string cropExtension(const std::string& _fileName) const;
    
public:
    static ResourceManager& getInstance();
    
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    void loadTexturesFromDirectory(const std::string& _pathToTextures);
    void loadFontsFromDirectory(const std::string& _pathTofonts);
    void loadMusicFromDirectory(const std::string& _pathToMusic);
    void loadGuiTheme(const std::string& _pathToTheme);
    
    std::shared_ptr<sf::Texture> createVoidTexture(const std::string& _textureName);
    void removeTexture(const std::string& _textureName);

    sf::Texture* getTexture(const std::string& _textureName) const;
    sf::Font* getFont(const std::string& _fontName) const;
    const std::vector<std::shared_ptr<sf::Music>>& getMusic() const;
    std::shared_ptr<tgui::Theme> getGuiTheme() const;
};

#endif //RESOURCE_MANGER_HPP
