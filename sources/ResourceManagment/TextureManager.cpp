#include "TextureManager.hpp"

TextureManager::TextureManager()
{}

TextureManager::TextureManager(std::string _pathToFiles)
{
	defaultPathToFiles = _pathToFiles;
}

void TextureManager::loadAllItemsFromDirectory()
{
	using namespace boost::filesystem;

	path base_dir(defaultPathToFiles);
	std::string extension(".png");

	for(directory_iterator it (base_dir); it != directory_iterator(); ++it) {
		path file_path = it->path();

		std::string file_name;
		if(is_regular_file(it->status()) &&
		   (boost::filesystem::extension(it->path()) == extension)) {
			file_name = basename(file_path);

			sf::Texture tmp_texture;
			tmp_texture.loadFromFile(defaultPathToFiles + file_name);
			items.insert(file_name,
				     ResourceHolder(file_name, std::make_unique<sf::Texture>());
		}
		
	}
}

