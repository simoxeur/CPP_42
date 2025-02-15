#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal class constructed" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal class destructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a) : type(a.getType())
{
    std::cout << "WrongAnimal class copied" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
    if(this != &a)
        type = a.getType();
    std::cout << "class WrongAnimal assigned" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "the WrongAnimal make a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}
