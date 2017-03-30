#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <experimental/filesystem>
#include <memory>
#include "ResourceManager.hpp"

using namespace std::filesystem::v1;

class TextureManager : public ResourceManager<sf::Texture>
{
private:
	std::string defaultPathToFiles; 
public:
	TextureManager(std::string pathToFiles);
	void loadAllItemsFromDirectory() override;		
};

#endif //TEXTURE_MANGER_HPP
