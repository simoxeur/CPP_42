#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <cstdlib>

void leaks()
{
    system("valgrind --leak-check=full --log-file=ttt.log ./prog");
}

int main()
{
    // atexit(leaks);
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);


    // more tests
    ICharacter* joe = new Character("joe");
    joe->equip(src->createMateria("ice"));
    me->unequip(0);
    me->unequip(0);
    me->use(0, *bob);
    std::cout << joe->getName() << "----> ";
    joe->use(0, *me);
    
    delete bob;
    delete me;
    delete joe;
    delete src;

    return 0;
}