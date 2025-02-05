#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name)
    : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap " << name << " has been constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& f)
    : ClapTrap(f.get_name(), f.get_hitPoints(), f.get_energyPoints(), f.get_attackDamage())
{
    std::cout << "FragTrap " << get_name() << "has been copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& f)
{
    if (this != &f){
        this->set_name(f.get_name());
        this->set_hitPoints(f.get_hitPoints());
        this->set_energyPoints(f.get_energyPoints());
        this->set_attackDamage(f.get_attackDamage());
    }
    std::cout << "FragTrap " << get_name() << " has been assigned" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << get_name() << " has been destroyed" << std::endl;
}

/*
// attack member function, i am not sure  if should overide the base function
void FragTrap::attack( const std::string& target )
{
    if (get_energyPoints() == 0){
        std::cout << "ScavTrap " << get_name() << " has can't attack" << std::endl;
    }
    set_energyPoints(get_energyPoints() - 1);
    std::cout << "FragTrap " << get_name() << " attacks " << target \
    << ", causing " << get_attackDamage() << " points of damage!" << std::endl;
}*/

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << get_name() << " requests a high five! ✋" << std::endl;
}