#ifndef TEXTURE_MANGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <boost/filesystem.hpp>
#include <memory>
#include "ResourceManager.hpp"

class TextureManager : public ResourceManager<sf::Texture>
{
private:
	std::string defaultPathToFiles; 
public:
	TextureManager();
	TextureManager(std::string pathToFiles);
	void loadAllItemsFromDirectory() override;

	
		
};

#endif //TEXTURE_MANGER_HPP
