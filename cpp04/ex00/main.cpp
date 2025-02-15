#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

void leaks()
{
    system("valgrind --leak-check=full --log-file=ttt.log ./prog");
}

int main()
{
    // atexit(leaks);
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~Other tests~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;


    const WrongAnimal* ttt = new WrongAnimal();
    const WrongAnimal* t = new WrongCat();

    std::cout << t->getType() << " " << std::endl;
    t->makeSound(); //will output the Animal sound!
    ttt->makeSound();

    // delete all allocated
    delete meta, delete i, delete j, delete t, delete ttt;
    
    return 0;
}