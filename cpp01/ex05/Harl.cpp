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

Harl::ptr Harl::complain_list[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

Harl::Harl(){}

Harl::~Harl(){}

void Harl::complain(std::string level)
{
    int i = -1;
    // int chech = (level == "DEBUG") * 1 + (level == "INFO") * 2 + .... - 1
    while (++i < 4){
        if (Harl::level[i] == level){
            (this->*complain_list[i])(); return;
    }   }

}