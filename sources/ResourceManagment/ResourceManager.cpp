#include "ResourceManager.hpp"
#include <iostream>

ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;
}

void ResourceManager::loadTexturesFromDirectory(const std::string& _pathToFiles)
{
    using namespace boost::filesystem;
    
    std::string valid_extension(".png");
    path pathToFiles = system_complete(_pathToFiles);
    
    for(directory_iterator it (pathToFiles); it != directory_iterator(); ++it) {
        if(is_regular_file(it->status()) && (it->path().extension() == valid_extension)) {
            
            auto texture = std::make_shared<sf::Texture>();
            texture->loadFromFile(it->path().string());
            
            std::string filename = cropExtension(it->path().filename().string());
            textures.insert(std::make_pair(filename, texture));
        }
    }
}

void ResourceManager::loadFontsFromDirectory(const std::string& _pathToFiles)
{
    using namespace boost::filesystem;
    
    std::string valid_extension(".ttf");
    path pathToFiles = system_complete(_pathToFiles);
    
    for(directory_iterator it (pathToFiles); it != directory_iterator(); ++it) {
        if(is_regular_file(it->status()) && (it->path().extension() == valid_extension)) {
            
            auto font = std::make_shared<sf::Font>();
            font->loadFromFile(it->path().string());
            
            std::string filename = cropExtension(it->path().filename().string());
            fonts.insert(std::make_pair(filename, font));
        }
    }
}

std::string ResourceManager::cropExtension(const std::string& _fileName) const
{
    std::size_t pointPos = _fileName.find_last_of(".");
    return _fileName.substr(0, pointPos);
}

std::shared_ptr<sf::Texture> ResourceManager::createVoidTexture(const std::string& _textureName)
{
    textures.insert(std::make_pair(_textureName, std::make_shared<sf::Texture>()));
    return textures[_textureName];
}

sf::Texture* ResourceManager::getTexture(const std::string& _textureName)
{
    auto found = textures.find(_textureName);
    
    if(found != textures.end())
        return found->second.get();
    else
        return nullptr;
}

void ResourceManager::removeTexture(const std::string& _textureName)
{
    textures.erase(textures.find(_textureName));
}

sf::Font* ResourceManager::getFont(const std::string& _fontName)
{
    auto found = fonts.find(_fontName);
    
    if(found != fonts.end())
        return found->second.get();
    else
        return nullptr;
}
