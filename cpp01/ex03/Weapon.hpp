#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon(std::string type);
        Weapon();
        ~Weapon();
        const std::string& getType();
        void setType(std::string type);
};

#endif