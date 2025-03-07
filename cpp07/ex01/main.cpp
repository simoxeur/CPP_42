#include "iter.hpp"

int main()
{
    int lenght = 10;
    int* arr = new int[lenght];
    for(int i = 0; i < lenght; i++){
        arr[i] = rand() % 25;
    }
    iter(arr, lenght, print<int>);
    std::cout << "-------------------------------\n";
    iter(arr, lenght, power<int>);
    iter(arr, lenght, print<int>);
    delete[] arr;
}