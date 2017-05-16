#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <boost/filesystem.hpp>
#include <string>

class ResourceManager
{
private:
    std::map<std::string, std::shared_ptr<sf::Texture>> textures;
    std::map<std::string, std::shared_ptr<sf::Font>> fonts;
    
private:
    ResourceManager() {}
    ~ResourceManager() {}
    std::string cropExtension(const std::string& _fileName) const;
    
public:
    static ResourceManager& getInstance();
    
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    
    void loadTexturesFromDirectory(const std::string& pathToFiles);
    void loadFontsFromDirectory(const std::string& pathToFiles);
    std::shared_ptr<sf::Texture> createVoidTexture(const std::string& _textureName);
    sf::Texture* getTexture(const std::string& _textureName);
    void removeTexture(const std::string& _textureName);
    sf::Font* getFont(const std::string& _fontName);
};

#endif //RESOURCE_MANGER_HPP
