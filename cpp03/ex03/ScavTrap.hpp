#ifndef SCAVTRAP_HPP
#define SCAVETRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap(std::string);
        ScavTrap(const ScavTrap& s);
        ~ScavTrap();
        ScavTrap& operator=(const ScavTrap& s);
        void attack(const std::string& target);
        void guardGate();

        // // getters
        // std::string get_name();
        // int get_hitPoints();
        // int get_energyPoints();
        // int get_attackDamage();
};

#endif