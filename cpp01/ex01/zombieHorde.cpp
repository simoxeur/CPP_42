#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if(N < 0)
        return NULL;
    Zombie *lst_zmb = new Zombie[N];
    for(int i = 0; i < N; i++){
        lst_zmb[i].set_name(name);
    }
    return lst_zmb;
}