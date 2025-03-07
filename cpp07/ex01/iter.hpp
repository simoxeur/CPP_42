#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T, typename U>
void iter(T* arr, std::size_t lenght, void (*func)(U&))
{
    for(std::size_t i = 0; i < lenght; i++){
        (*func)(arr[i]);
    }
}

template <typename T>
void power(T& a)
{
    a = a * a;
}

template <typename T>
void print(T const & x)
{
    std::cout << x << std::endl;
    return;
}

#endif