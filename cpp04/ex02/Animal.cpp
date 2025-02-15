#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal class constructed" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal class destructed" << std::endl;
}

Animal::Animal(const Animal& a) : type(a.getType())
{
    std::cout << "Animal class copied" << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
    if(this != &a)
        type = a.getType();
    std::cout << "class Animal assigned" << std::endl;
    return *this;
}

std::string Animal::getType() const
{
    return type;
}
