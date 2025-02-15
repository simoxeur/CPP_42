#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\
ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put\
enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for\
years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain(std::string level)
{
    int l_index = (level == "DEBUG") * 1 + (level == "INFO") * 2
        + (level == "WARNING") * 3 + (level == "ERROR") * 4 +  - 1;
    while (l_index < 4){
        switch (l_index)
        {
        case 0:
            debug(), l_index++;
            break;
        case 1:
            info(), l_index++;
            break;
        case 2:
            warning(), l_index++;
            break;
        case 3:
            error(), l_index++;
            return;
        }
    }
    std::cerr << "[ Probably complaining about insignificant problems ]\n" ; return;
}