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

sf::Texture* ResourceManager::getTexture(const std::string& name)
{
    auto found = textures.find(name);
    
    if(found != textures.end())
        return found->second.get();
    else
        return nullptr;
}

sf::Font* ResourceManager::getFont(const std::string& name)
{
    auto found = fonts.find(name);
    
    if(found != fonts.end())
        return found->second.get();
    else
        return nullptr;
}
