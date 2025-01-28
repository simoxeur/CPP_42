#include "HumanA.hpp"

void HumanA::attack(void)
{
    std::cout << _name << " attacks with their " << wA.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &wp) : _name{name}, wA{wp} {}

HumanA::~HumanA(){}