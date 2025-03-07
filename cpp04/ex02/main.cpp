#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "the animal is a " << i->getType() << std::endl;
    i->makeSound();
    std::cout << "the animal is a " << j->getType() << std::endl;
    j->makeSound();


    delete j; //should not create a leak
    delete i;

    std::cout << "\n~~~~~~~~~~~~~~~~~~~~more tests~~~~~~~~~~~~~~~~~~~~~~~\n\n";

    Animal* aa = new Dog();
    aa->makeSound();
    // this exercice will show how we could avoid this kind of issues
    // j->Animal::makeSound(); 
    delete aa;




    return 0;

}