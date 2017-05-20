#include "../../include/ResourceManagment/ResourceManager.hpp"

ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;
}

void ResourceManager::loadTexturesFromDirectory(const std::string& _pathToTextures)
{
    using namespace boost::filesystem;
    
    std::string valid_extension(".png");
    path pathToFiles = system_complete(_pathToTextures);
    
    for(directory_iterator it (pathToFiles); it != directory_iterator(); ++it) {
        if(is_regular_file(it->status()) && (it->path().extension() == valid_extension)) {
            
            auto texture = std::make_shared<sf::Texture>();
            texture->loadFromFile(it->path().string());
            
            std::string filename = cropExtension(it->path().filename().string());
            textures.insert(std::make_pair(filename, texture));
        }
    }
}

void ResourceManager::loadFontsFromDirectory(const std::string& _pathToFonts)
{
    using namespace boost::filesystem;
    
    std::string valid_extension(".ttf");
    path pathToFiles = system_complete(_pathToFonts);
    
    for(directory_iterator it (pathToFiles); it != directory_iterator(); ++it) {
        if(is_regular_file(it->status()) && (it->path().extension() == valid_extension)) {
            
            auto font = std::make_shared<sf::Font>();
            font->loadFromFile(it->path().string());
            
            std::string filename = cropExtension(it->path().filename().string());
            fonts.insert(std::make_pair(filename, font));
        }
    }
}

void ResourceManager::loadMusicFromDirectory(const std::string& _pathToMusic)
{
    using namespace boost::filesystem;
    
    std::string valid_extension(".ttf");
    path pathToFiles = system_complete(_pathToMusic);
    
    for(directory_iterator it (pathToFiles); it != directory_iterator(); ++it) {
        if(is_regular_file(it->status()) && (it->path().extension() == valid_extension)) {
            
            auto font = std::make_shared<sf::Font>();
            font->loadFromFile(it->path().string());
            
            std::string filename = cropExtension(it->path().filename().string());
            fonts.insert(std::make_pair(filename, font));
        }
    }
}

void ResourceManager::loadGuiTheme(const std::string& _pathToTheme)
{
    guiTheme = tgui::Theme::create(_pathToTheme);
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

void ResourceManager::removeTexture(const std::string& _textureName)
{
    textures.erase(textures.find(_textureName));
}

sf::Texture* ResourceManager::getTexture(const std::string& _textureName) const
{
    auto found = textures.find(_textureName);
    
    if(found != textures.end())
        return found->second.get();
    else
        return nullptr;
}

sf::Font* ResourceManager::getFont(const std::string& _fontName) const
{
    auto found = fonts.find(_fontName);
    
    if(found != fonts.end())
        return found->second.get();
    else
        return nullptr;
}

std::shared_ptr<tgui::Theme> ResourceManager::getGuiTheme() const
{
    return guiTheme;
}
