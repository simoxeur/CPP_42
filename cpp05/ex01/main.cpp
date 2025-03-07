#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat moha("mohamed", 1);
        std::cout << moha << '\n';
        moha--;
        std::cout << moha << '\n';
        Form test("test_form", 1, 1);
        std::cout << test << '\n';
        moha.signForm(test);
        std::cout << test << '\n';
        std::cout << "manualy test if really signed --> " << (test.get_SignStatus() == true ? "signed" : "NOOO, not signed") << std::endl;
        moha++;
        moha.signForm(test);
        std::cout << test << '\n';
        std::cout << "manualy test if really signed --> " << (test.get_SignStatus() == true ? "signed" : "NOOO, not signed") << std::endl;
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