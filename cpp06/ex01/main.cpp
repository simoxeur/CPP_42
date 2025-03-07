#include "Serializer.hpp"

int main()
{
    Data* data = new Data;
    data->name = "mohamed";
    data->age = 24;
    std::cout << "data pointer at start = " << data << '\n';
    std::cout << "----------------------------------------\n";
    uintptr_t test_ptr = Serializer::serialize(data);
    std::cout << "the inter converted it to, is = " << test_ptr << '\n';
    std::cout << "----------------------------------------\n";
    Data* re = Serializer::deserialize(test_ptr);
    std::cout << "the pointer recreated unsing uintptr_t variable = " << re << '\n';

    if(data == re)
        std::cout << "\n|___success to get the same ptr as the original___|\n";
    
    delete data;
}