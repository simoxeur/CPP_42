#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request", 72, 45)
{
    set_target(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& s)
    : AForm(s)
{
    set_target(s.get_target());
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& s)
{
    if(this != &s)
    {
        AForm::operator=(s);
        set_target(s.get_target());
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::beSigned(const Bureaucrat& b)
{
    if(b.get_grade() > get_gradeToSign())
        throw GradeTooLowException();
    set_signed(true);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(get_SignStatus() == false)
        throw NotSigned();
    if(executor.get_grade() > get_gradeToExec())
        throw GradeTooLowException();
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << get_target() << " has beed robotomized" << std::endl;
    else
        std::cout << "the robotomy failed for " << get_target() << " request" << std::endl;
}
