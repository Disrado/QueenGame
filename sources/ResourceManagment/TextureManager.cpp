#include "TextureManager.hpp"

TextureManager::TextureManager(std::string _pathToFiles)
{
	defaultPathToFiles = _pathToFiles;
}

void TextureManager::loadAllItemsFromDirectory()
{
	path base_dir(defaultPathToFiles);
	std::string extension(".png");

	for(auto it : directory_iterator(base_dir)) {
		if(is_regular_file(it.status())) {
			auto _texture = new sf::Texture();
			_texture->loadFromFile(it.path());
			items.insert(std::pair<std::string, ResourceHolder>(it.path().filename(),
									    ResourceHolder(_texture)));
		}
		
	}
}

