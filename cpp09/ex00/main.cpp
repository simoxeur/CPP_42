#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac > 2){
        std::cout << "Bad Argument\nUsage: ./btc <input_file>\n";
        return 1;
    }
    try
    {
        Ressources ressource(av[1]);
        ressource.validate_infile();
        ressource.display();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}