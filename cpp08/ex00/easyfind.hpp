#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <deque>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int to_find);

#endif