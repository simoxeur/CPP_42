#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation", 145, 137)
{
    set_target(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& s)
    : AForm(s)
{
    set_target(s.get_target());
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& s)
{
    if(this != &s)
    {
        AForm::operator=(s);
        set_target(s.get_target());
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::beSigned(const Bureaucrat& b)
{
    if(b.get_grade() > get_gradeToSign())
        throw GradeTooLowException();
    set_signed(true);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if(get_SignStatus() == false)
        throw NotSigned();
    if(executor.get_grade() > get_gradeToExec())
        throw GradeTooLowException();
    std::string name = get_target() + "_shrubbery";
    std::ofstream out(name.c_str());
    if(!out.is_open())
        throw FailToOpen();
    out  << "\n\n\n\n                      _-_\n"
         << "                   /~~   ~~\\\n"
         << "                /~~         ~~\\\n"
         << "               {               }\n"
         << "                \\  _-     -_  /\n"
         << "                  ~  \\ //  ~\n"
         << "               _- -   | | _- _\n"
         << "                 _ -  | |   -_\n"
         << "                     // \\\\\n";

    out.close();
}

const char* ShrubberyCreationForm::FailToOpen::what() const throw()
{
    return "Fail to open the file!";
}