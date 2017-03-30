#include "TextureManager.hpp"

TextureManager::TextureManager() {}

static TextureManager const& TextureManager::getInstance()
{
	static TextureManager TManager;
	return TManager;
}

void TextureManager::loadAllItemsFromDirectory(std::string _pathToFiles)
{
	using namespace boost::filesystem;
	using namespace std;
	
	std::string valid_extension(".png");
	path pathToFiles(_pathToFiles);
	
	for(directory_iterator it (pathToFiles); it != directory_iterator(); ++it) {
		if(is_regular_file(it->status()) && (it->path().extension() == valid_extension)) {

			auto _texture = new sf::Texture();
			_texture->loadFromFile(_pathToFiles + it->path().string());

			pair<string, ResourceHolder> item(it->path().filename().string(), _texture);
			items.insert(item);
		}
	}
}
