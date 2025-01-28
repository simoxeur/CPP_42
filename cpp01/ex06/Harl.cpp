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

std::string Harl::level[] {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain(std::string level)
{
    int i = -1;
    while (++i < 4){
        if (Harl::level[i] == level){
            break;
    }   }
    while (i < 4){
        switch (i)
        {
        case 0:
            debug(), i++;
            break;
        case 1:
            info(), i++;
            break;
        case 2:
            warning(), i++;
            break;
        case 3:
            error(), i++;
            return;
        }
    }
    std::cerr << "[ Probably complaining about insignificant problems ]\n" ; return;
}