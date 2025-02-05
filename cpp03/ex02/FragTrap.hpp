#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap( std::string name );
        FragTrap( const FragTrap& );
        FragTrap& operator=( const FragTrap& );
        ~FragTrap();

        // void attack( const std::string& target ); // the subjest didn't require this
        void highFivesGuys(void);
};

#endif