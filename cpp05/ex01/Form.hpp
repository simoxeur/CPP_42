#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool is_signed;
        const int gradeToSign;
        const int gradeToExec;

    public:
        Form();
        Form(std::string, const int, const int);
        Form(const Form&);
        Form& operator=(const Form&);
        ~Form();

        // getters
        std::string get_name(void) const;
        bool get_SignStatus(void) const;
        int get_gradeToSign(void) const;
        int get_gradeToExec(void) const;

        void beSigned(const Bureaucrat&);

        // Form exception class
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};


std::ostream& operator<<(std::ostream&, const Form&);

#endif