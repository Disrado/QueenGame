#ifndef RESOURCE_HOLDER_HPP
#define RESOURCE_HOLDER_HPP

template <class T>
class ResourceHolder
{
private:
	std::shared_ptr<T> item;
	
public:
	ResourceHolder(std::shared_ptr<T> _item) {
		item = _item;
	}
	
	T* getValue() {
		return item.get();
	}
	
};

#endif //RESOURCE_HOLDER_HPP
