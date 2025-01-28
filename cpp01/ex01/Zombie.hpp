#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class   Zombie
{
    private:
        std::string _name;

    public:
        Zombie();
        ~Zombie( void );
        void set_name( std::string name);
        void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif