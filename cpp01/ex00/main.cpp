#include "Zombie.hpp"
#include <stdlib.h>

void leaks(void)
{
    system("valgrind \
        --leak-check=full \
        --show-leak-kinds=all \
        --track-origins=yes \
        --log-file=valgrind-output.txt \
        ./Zombie");
}

int main()
{
    // atexit(leaks);
    Zombie *zz = newZombie("moha");
    zz->announce();
    randomChump("zabzoub");
    delete zz;
}