#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : name(name), grade(grade)
{
    if (grade <= 0)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b)
    : name(b.name), grade(b.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
    if(this != &b)
        grade = b.grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){}

std::string Bureaucrat::get_name(void) const
{
    return name;
}

int Bureaucrat::get_grade(void) const
{
    return grade;
}

void Bureaucrat::signForm(AForm& f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << get_name() << " signed " << f.get_name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << get_name() << " couldn't sign " << "because his grade is too low\n";
    }
}

void Bureaucrat::executeForm(AForm const & Aform)
{
    try
    {
        Aform.execute(*this);
        std::cout << get_name() << " executed " << Aform.get_name() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << get_name() << " can't execute the form "\
        << Aform.get_name() << " because ";
        std::cout << (Aform.get_SignStatus() == false ? "the form is not signed" : (get_grade() > Aform.get_gradeToExec() ? "his grade is too low" : "an undefined reason"));
        std::cout << std::endl;
    }
}

Bureaucrat Bureaucrat::operator++(int)
{
    Bureaucrat tmp(*this);
    if(this->grade - 1 <= 0)
        throw GradeTooHighException();
    this->grade--;
    return tmp;
}

Bureaucrat Bureaucrat::operator--(int)
{
    Bureaucrat tmp(*this);
    if(this->grade + 1 > 150)
        throw GradeTooLowException();
    this->grade++;
    return tmp;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.get_name() << ", bureaucrat grade " << b.get_grade() << ".";
    return out;
}


// BureaucratExeption class definition

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "the grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "the grade is too low";
}
