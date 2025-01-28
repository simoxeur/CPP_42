#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB
{
    private:
        std::string _name;
        Weapon *wB;
    
    public:
        HumanB(std::string name);
        ~HumanB();
        void setWeapon(Weapon &wpn);
        void attack(void);
        std::string get()
        {
            return wB->getType();
        }
};

#endif