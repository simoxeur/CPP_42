#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanA
{
    private:
        std::string _name;
        Weapon &wA;

    public:
        HumanA(std::string name, Weapon &wp);
        ~HumanA();
        void attack(void);
        std::string get()
        {
            return wA.getType();
        }
};

#endif