#include "Form.hpp"

Form::Form()
    : gradeToSign(0)
    , gradeToExec(0) {}

Form::Form(std::string name, const int g_tosign, const int g_toexec)
    : name(name)
    , is_signed(false)
    , gradeToSign(g_tosign)
    , gradeToExec(g_toexec)
{
    if (gradeToSign <= 0 || gradeToExec <= 0)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& f)
    : name(f.name)
    , is_signed(f.is_signed)
    , gradeToSign(f.gradeToSign)
    , gradeToExec(f.gradeToExec)
    {}

Form& Form::operator=(const Form& f)
{
    if(this != &f){
        is_signed = f.is_signed;
    }
    return *this;
}

Form::~Form(){}

std::string Form::get_name() const { return name; }

bool Form::get_SignStatus() const { return is_signed; }

int Form::get_gradeToSign() const { return gradeToSign; }

int Form::get_gradeToExec() const { return gradeToExec; }

void Form::beSigned(const Bureaucrat& b)
{
    if(b.get_grade() > get_gradeToSign())
        throw GradeTooLowException();
    is_signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << f.get_name() << ", status " << (f.get_SignStatus() == true ? "signed" : "not signed") \
    << ", grade needed to sign: " << f.get_gradeToSign() << ", grade needed to execute: " << f.get_gradeToExec();
    return out;
}

// Form Exeption class definition

const char* Form::GradeTooHighException::what() const throw()
{
    return "the grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "the grade is too low";
}
