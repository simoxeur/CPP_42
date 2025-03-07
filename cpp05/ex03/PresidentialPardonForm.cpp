#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5)
{
    set_target(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& s)
    : AForm(s)
{
    set_target(s.get_target());
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& s)
{
    if(this != &s)
    {
        AForm::operator=(s);
        set_target(s.get_target());
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::beSigned(const Bureaucrat& b)
{
    if(b.get_grade() > get_gradeToSign())
        throw GradeTooLowException();
    set_signed(true);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(get_SignStatus() == false)
        throw NotSigned();
    if(executor.get_grade() > get_gradeToExec())
        throw GradeTooLowException();
    std::cout << get_target() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
