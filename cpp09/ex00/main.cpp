#include "BitcoinExchange.hpp"

void f(void)
{
    system("lsof -c btc");
}

int main(int ac, char **av)
{
    atexit(f);
    if(ac > 2){
        std::cout << "Bad Argument\nUsage: ./btc <input_file>\n";
        return 1;
    }
    try
    {
        Ressources ressource(av[1]);
        Ressources test(ressource);
        test.validate_infile();
        test.display();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    while(1);
    
}