#include "ClapTrap.hpp"

int main()
{
    ClapTrap med("mido");
    std::string target("abdo");
    med.attack(target);
    med.takeDamage(7);
    med.beRepaired(5);
}