#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int to_find)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), to_find);
    if(it == container.end())
        std::cout << to_find << ": not found" << std::endl;
    return it;
}