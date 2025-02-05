#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << name << " has been constructed" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " has been destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
    : name(c.name)
    , hit_points(c.hit_points)
    , energy_points(c.energy_points)
    , attack_damage(c.attack_damage)
{
    std::cout << "ClapTrap " << name << "has beed copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
    if (this != &c){
        this->name = c.name;
        this->hit_points = c.hit_points;
        this->energy_points = c.energy_points;
        this->attack_damage = c.attack_damage;
    }
    std::cout << "ClapTrap " << name << " has been assigned" << std::endl;
    return (*this);
}

void ClapTrap::attack( const std::string& target )
{
    if (hit_points == 0 || energy_points == 0){
        std::cout << "ClapTrap " << name << " can't attack" << std::endl;
        return ;
    }
    energy_points--;
    std::cout << "ClapTrap " << name << " attacks " << target \
    << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points == 0 || energy_points == 0){
        std::cout << "ClapTrap " << name << " can't take more damage" << std::endl;
        return ;
    }
    hit_points = (hit_points > (int)amount) ? hit_points - amount : 0;
    std::cout << "ClapTrap " << name << " take damage "\
    << ", taken " << amount << " points of damage!" \
    << " (hitPoint = " << hit_points << ")"<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points == 0 || energy_points == 0)
        return ;
    energy_points--;
    hit_points += amount;
    std::cout << "ClapTrap " << name << " is repaired " \
    << " gaining " << amount << " points" \
    << " (hitPoints = " << hit_points << ")" << std::endl;
}
