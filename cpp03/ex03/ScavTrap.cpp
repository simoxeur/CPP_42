#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap " << name << " has been constructed" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& s)
    : ClapTrap(s.get_name(), s.get_hitPoints(), s.get_energyPoints(), s.get_attackDamage())
{
    std::cout << "ScavTrap " << get_name() << "has been copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
    if (this != &s){
        this->set_name(s.get_name());
        this->set_hitPoints(s.get_hitPoints());
        this->set_energyPoints(s.get_energyPoints());
        this->set_attackDamage(s.get_attackDamage());
    }
    std::cout << "ScavTrap " << get_name() << " has been assigned" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << get_name() << " has been destroyed" << std::endl;
}

void ScavTrap::attack( const std::string& target )
{
    if (get_energyPoints() == 0){
        std::cout << "ScavTrap " << get_name() << " has can't attack" << std::endl;
    }
    set_energyPoints(get_energyPoints() - 1);
    std::cout << "ScavTrap " << get_name() << " attacks " << target \
    << ", causing " << get_attackDamage() << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << get_name() << " is now in Gate keeper mode" << std::endl;
}
