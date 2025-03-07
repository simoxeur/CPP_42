#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(){}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name", 100, 50, 30)
    , ScavTrap(name)
    , FragTrap(name)
    , name(name)
{
    std::cout << "DiamondTrap " << name << " has been contructed" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d)
    : ClapTrap(d.get_name(), d.get_hitPoints()
             , d.get_energyPoints(), d.get_attackDamage())
    , ScavTrap(d.name)
    , FragTrap(d.name)
    , name(d.name)
{
    std::cout << "diamonTrap" << d.name << " has beed copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d)
{
    if (this != &d){
        this->name = d.name;
        this->set_name(d.get_name());
        this->set_hitPoints(d.get_hitPoints());
        this->set_energyPoints(d.get_energyPoints());
        this->set_attackDamage(d.get_attackDamage());
    }
    std::cout << "DiamondTrap" << name << " has beed assigned" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << name << " has beed destroyed" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "this is DiamodTrap: " << name
    << " and ClapTrap: " << get_name() << std::endl;
}