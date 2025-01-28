#include "HumanB.hpp"

void HumanB::attack(void)
{
    std::cout << _name << " attacks with their " << wB->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &wp)
{
    delete wB;
    wB = &wp;
}

HumanB::HumanB(std::string name) : _name{name}, wB{new Weapon} {}

HumanB::~HumanB(){}