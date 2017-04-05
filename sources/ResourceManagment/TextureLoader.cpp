#include "TextureLoader.hpp"
#include "iostream"

TextureLoader::TextureLoader() {}

TextureLoader& TextureLoader::Instance()
{
    static TextureLoader instance;
    return instance;
}

void TextureLoader::loadAllItemsFromDirectory(const std::string& _pathToFiles)
{
    using namespace boost::filesystem;
    using namespace std;
    using  sf::Texture;
    
    string valid_extension(".png");
    path pathToFiles = system_complete(_pathToFiles);
    
    for(directory_iterator it (pathToFiles); it != directory_iterator(); ++it) {
        if(is_regular_file(it->status()) && (it->path().extension() == valid_extension)) {
            
            auto texture = make_shared<Texture>();
            texture->loadFromFile(it->path().string());
            
            std::string filename = this->cropExtension(it->path().filename().string());
            items.insert(std::make_pair(filename, texture));
        }
    }
}

void TextureLoader::loadItemFromDirectory(const std::string& _pathToFile)
{
    using namespace boost::filesystem;
    
    path pathToFile(_pathToFile);
    std::string valid_extension(".png");
    
    if(exists(_pathToFile) && (pathToFile.filename().extension() == valid_extension)) {
        auto texture = new sf::Texture();
        texture->loadFromFile(_pathToFile);
    }
}

sf::Texture* TextureLoader::getItemByName(const std::string& filename)
{
    auto found = items.find(filename);
    
    if(found != items.end())
        return found->second.getValue();
    else
        return nullptr;
}

std::string TextureLoader::cropExtension(const std::string& _fileName) const
{
    std::size_t pointPos = _fileName.find_last_of(".");
    return _fileName.substr(0, pointPos);
}
