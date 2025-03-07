#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void leaks()
{
    system("valgrind --leak-check=full --log-file=leaks.log ./prog");
}

int main()
{
    // atexit(leaks);
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm*tree = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* pardon = someRandomIntern.makeForm("presidential pardon", "anas");
        Bureaucrat moha("mohamed", 1);
        if(rrf) // i reutrn NULL i case of not found Form
        {
            moha.signForm(*rrf);
            moha.executeForm(*rrf);
            delete rrf;
        }
        if(tree){
            moha.signForm(*tree);
            moha.executeForm(*tree);
            delete tree;
        }
        if(pardon){
            moha.signForm(*pardon);
            moha.executeForm(*pardon);
            delete pardon;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(...)
    {
        std::cout << "exit with an undefined exception\n";
    }}