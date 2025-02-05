#include "ScavTrap.hpp"

int main()
{
    ScavTrap dodo("azoz");
    std::string target("nono");
    dodo.attack(target);
    dodo.takeDamage(7);
    dodo.beRepaired(2);
    dodo.guardGate();
}