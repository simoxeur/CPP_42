#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void leaks()
{
    system("valgrind --leak-check=full --log-file=leaks.log ./prog");
}

int main()
{
    try
    {
        Bureaucrat moha("mohamed", 20);
        std::cout << moha << '\n';
        moha--;
        std::cout << moha << '\n';
        AForm* tree = new ShrubberyCreationForm("home");
        AForm* robotomy = new RobotomyRequestForm("anas");
        AForm* pardon = new PresidentialPardonForm("moha");
        moha.signForm(*tree);
        moha.signForm(*robotomy);
        moha.signForm(*pardon);
        moha.executeForm(*tree);
        moha.executeForm(*robotomy);
        moha.executeForm(*pardon);
        Bureaucrat pris("vander", 1);
        pris.executeForm(*pardon);
        delete tree;
        delete robotomy;
        delete pardon;
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