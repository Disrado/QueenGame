#ifndef RESOURCE_MANAGER_HPP
#define RESOURCE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"

template <class T>
class ResourceLoader
{
protected:
    std::map<std::string, ResourceHolder<T>> items;
    
protected:
    virtual ~ResourceLoader() {}
    
    virtual void loadAllItemsFromDirectory(const std::string&) = 0;
    virtual T* getItem(const std::string&) = 0;
};

#endif //RESOURCE_MANAGER_HPP
