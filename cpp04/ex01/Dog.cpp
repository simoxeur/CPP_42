#include "Dog.hpp"

Dog::Dog() : Animal(), dog_brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog class constructed" << std::endl;
}

Dog::~Dog()
{
    delete dog_brain;
    std::cout << "Dog class desctructed" << std::endl;
}

Dog::Dog(const Dog& d)
    : Animal(d), dog_brain(new Brain(*d.dog_brain))
{
    type = d.getType();
    std::cout << "Dog class copied" << std::endl;
}

Dog& Dog::operator=(const Dog& d)
{
    if(this != &d){
        Animal::operator=(d);
        type = d.getType();
        delete dog_brain;
        dog_brain = new Brain(*d.dog_brain);
    }
    std::cout << "Dog class assigned" << std::endl;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "the Dog say woooof" << std::endl;
}

std::string Dog::getType() const
{
    return type;
}