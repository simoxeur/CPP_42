#include "RPN.hpp"

int main(int ac, char **av)
{
    if(ac != 2){
        std::cout << "Bad argument\nUsage ./RPN rpn_input";
        return 1;
    }
    try
    {
        RPN test(av[1]);
        test.calculate_rpn();
        std::cout << test.get_result() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}