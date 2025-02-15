#include "Cat.hpp"

Cat::Cat() : Animal(), cat_brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat class constructed" << std::endl;
}

Cat::~Cat()
{
    delete cat_brain;
    std::cout << "Cat class desctructed" << std::endl;
}

Cat::Cat(const Cat& c)
    : Animal(c), cat_brain(new Brain(*c.cat_brain))
{
    type = c.getType();
    std::cout << "Cat class copied" << std::endl;
}

Cat& Cat::operator=(const Cat& c)
{
    if(this != &c){
        Animal::operator=(c);
        type = c.getType();
        delete cat_brain;
        cat_brain = new Brain(*c.cat_brain);
    }
    std::cout << "Cat class assigned" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "the cat says myaw" << std::endl;
}

std::string Cat::getType() const
{
    return type;
}