#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name, int hit_point = 10, int energy_points = 10, int attack_damage = 0)
    : name(name)
    , hit_points(hit_point)
    , energy_points(energy_points)
    , attack_damage(attack_damage)
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

// getters

std::string ClapTrap::get_name() const { return name; }

int ClapTrap::get_hitPoints() const { return hit_points; }

int ClapTrap::get_energyPoints() const { return energy_points; }

int ClapTrap::get_attackDamage() const { return attack_damage; }

// setters

void ClapTrap::set_name(const std::string _name){ name = _name; }

void ClapTrap::set_hitPoints(int h_p ) { hit_points = h_p; }

void ClapTrap::set_energyPoints(int e_p) { energy_points = e_p; }

void ClapTrap::set_attackDamage(int a_d) { attack_damage = a_d; }

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
