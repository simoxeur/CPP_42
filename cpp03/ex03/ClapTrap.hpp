#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;

    public:
        ClapTrap();
        ClapTrap( std::string, int, int, int );
        ~ClapTrap();
        ClapTrap( const ClapTrap& );
        ClapTrap& operator=(const ClapTrap&);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        // getters
        std::string get_name() const;
        int get_hitPoints() const;
        int get_energyPoints() const;
        int get_attackDamage() const;
        // setters
        void set_name(const std::string);
        void set_hitPoints( int h_p);
        void set_energyPoints( int );
        void set_attackDamage( int );
};

#endif