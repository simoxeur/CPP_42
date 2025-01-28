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
    int N = 5;
    std::string name = "zabzoub";
    Zombie *zz = zombieHorde(N, name);
    for(int i = 0; i < N; i++){
        zz[i].announce();
    }
    delete []zz;
}