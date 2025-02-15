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
    atexit(leaks);
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "the animal is a " << i->getType() << std::endl;
    i->makeSound();
    std::cout << "the animal is a " << j->getType() << std::endl;
    j->makeSound();

    j->Animal::makeSound(); // the next exercice will show how we could avoid this kind of issues

    delete j; //should not create a leak
    delete i;

    // the  array of animals
    std::cout << "\n~~~~~~~~~~~~~~~~~other tests~~~~~~~~~~~~~~~~\n\n";
    int len = 10;
    Animal* animal_arr[len];
    for(int i = 0; i < len / 2; i++){
        animal_arr[i] = new Dog();
    }
    for(int i = len / 2; i < len; i++){
        animal_arr[i] = new Cat();
    }
    for(int i = 0; i < len; i++){
        animal_arr[i]->makeSound();
    }
    for(int i = 0; i < len; i++){
        delete animal_arr[i];
    }

    return 0;
}