#include <iostream>
#include <string>

std::string str_up(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
    return str;
}

int main(int ac, char **av)
{
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for(int i = 1; i < ac; i++)
    {
        std::cout << str_up(av[i]);
    }
    std::cout << std::endl;
}