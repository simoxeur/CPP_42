#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class   Zombie
{
    private:
        std::string _name;

    public:
        void announce( void );
        Zombie( std::string name);
        ~Zombie( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif