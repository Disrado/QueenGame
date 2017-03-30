#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <boost/filesystem.hpp>
#include <string>
#include "ResourceLoader.hpp"

class TextureLoader : public ResourceLoader<sf::Texture>
{
private:
	std::string defaultPathToFiles; 

private:
	TextureLoader();	

	std::string cropExtension(const std::string& _fileName) const;
	
public:
	static TextureLoader& Instance();

	TextureLoader(const TextureLoader&) = delete;
	TextureLoader& operator=(const TextureLoader&) = delete;
	
	void loadAllItemsFromDirectory(const std::string& pathToFiles) override;		
	void loadItemFromDirectory(const std::string& pathToFile) override;
        sf::Texture* getItemByName(const std::string& filename) override;
};

#endif //TEXTURE_MANGER_HPP
