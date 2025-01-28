#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac != 2){
        std::cerr << "Bad arguments\nusage: ./harlfilter <Harl complain>\n";
        return 1;
    }
    Harl test;
    test.complain(av[1]);
}