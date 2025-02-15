#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat class constructed" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat class desctructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& d)
    : WrongAnimal(d)
{
    type = d.getType();
    std::cout << "WrongCat class copied" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& d)
{
    if(this != &d){
        WrongAnimal::operator=(d);
        type = d.getType();
    }
    std::cout << "WrongCat class assigned" << std::endl;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "the WrongCat says myaw" << std::endl;
}

std::string WrongCat::getType() const
{
    return type;
}