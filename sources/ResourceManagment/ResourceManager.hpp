#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>

template <class T>
class ResourceManager
{
protected:
	class ResourceHolder
	{
	private:
		std::string name;
		std::unique_ptr<T> item;
		
	public:
		ResourceHolder(std::string _name, std::unique_ptr<T> _item) :
			name(_name), item(_item)
			{}
	};
	
protected:
	std::map<std::string, ResourceHolder> items;
	
public:
	virtual ~ResourceManager();
	
	virtual void loadAllItemsFromDirectory() = 0;
	virtual void loadItemByName() = 0;
	virtual ResourceHolder getItem(std::string) = 0;
};

#endif //RESOURCE_MANAGER_HPP
