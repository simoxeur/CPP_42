#include "AForm.hpp"

AForm::AForm()
    : gradeToSign(0)
    , gradeToExec(0) {}

AForm::AForm(std::string name, const int g_tosign, const int g_toexec)
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

AForm::AForm(const AForm& f)
    : name(f.name)
    , is_signed(f.is_signed)
    , gradeToSign(f.gradeToSign)
    , gradeToExec(f.gradeToExec)
    {}

AForm& AForm::operator=(const AForm& f)
{
    if(this != &f){
        is_signed = f.is_signed;
    }
    return *this;
}

AForm::~AForm(){}


std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << f.get_name() << ", status " << (f.get_SignStatus() == true ? "signed" : "not signed") \
    << ", grade needed to sign: " << f.get_gradeToSign() << ", grade needed to execute: " << f.get_gradeToExec();
    return out;
}

std::string AForm::get_name() const { return name; }

std::string AForm::get_target(void) const { return target; }

bool AForm::get_SignStatus() const { return is_signed; }

int AForm::get_gradeToSign() const { return gradeToSign; }

int AForm::get_gradeToExec() const { return gradeToExec; }

void AForm::set_target(std::string target)
{
    this->target = target;
}

void AForm::set_signed(bool is_it)
{
    this->is_signed = is_it;
}


// AForm Exeption class definition

const char* AForm::GradeTooHighException::what() const throw()
{
    return "the grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "the grade is too low";
}

const char* AForm::NotSigned::what() const throw()
{
    return "the form is not signd\n";
}
