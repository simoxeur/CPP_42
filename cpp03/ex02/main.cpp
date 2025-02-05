#include "FragTrap.hpp"

int main()
{
    FragTrap frag("BoomBot");

    frag.attack("Evil Robot");
    frag.highFivesGuys();
    frag.takeDamage(40);
    frag.beRepaired(20);

    return 0;
}