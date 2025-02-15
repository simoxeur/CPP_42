#include "Dog.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << "Dog class constructed" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog class desctructed" << std::endl;
}

Dog::Dog(const Dog& d)
    : Animal(d)
{
    type = d.getType();
    std::cout << "Dog class copied" << std::endl;
}

Dog& Dog::operator=(const Dog& d)
{
    if (this != &d){
        Animal::operator=(d);
        type = d.getType();
    }
    std::cout << "Dog class assigned" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "the Dog say woooof" << std::endl; // change woof by bark the same for cat
}

std::string Dog::getType() const
{
    return type;
}