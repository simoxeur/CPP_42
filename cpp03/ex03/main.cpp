#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap d("Destroyer");

    d.whoAmI();
    d.attack("Enemy");
    d.takeDamage(30);
    d.beRepaired(20);

    return 0;
}