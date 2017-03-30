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
		T* item;
		
	public:
		ResourceHolder(T* _item)
			{
				item = _item;
			}
		~ResourceHolder()
			{
				delete item;
			}
	};
	
protected:
	std::map<std::string, ResourceHolder> items;
	
protected:
	virtual ~ResourceManager() {}
	
	virtual void loadAllItemsFromDirectory() = 0;
	virtual void loadItemByName() = 0;
	virtual ResourceHolder getItem(std::string) = 0;
};

#endif //RESOURCE_MANAGER_HPP
