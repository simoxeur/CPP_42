#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat moha("mohamed", 149);
        std::cout << moha << '\n';
        moha--;
        std::cout << moha << '\n';
        moha--;
        std::cout << moha << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(...)
    {
        std::cout << "exit with an undefined exception\n";
    }
}