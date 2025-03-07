#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        std::string target;
        bool is_signed;
        const int gradeToSign;
        const int gradeToExec;

    public:
        AForm();
        AForm(std::string, const int, const int);
        AForm(const AForm&);
        AForm& operator=(const AForm&);
        virtual ~AForm();

        // getters
        virtual std::string get_name(void) const;
        virtual std::string get_target(void) const;
        virtual bool get_SignStatus(void) const;
        virtual int get_gradeToSign(void) const;
        virtual int get_gradeToExec(void) const;

        // setters
        void set_target(std::string);
        void set_signed(bool);

        virtual void beSigned(const Bureaucrat&) = 0;
        virtual void execute(Bureaucrat const & executor) const = 0;

        // AForm exception class
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

        class NotSigned : public std::exception
        {
            public:
                const char* what() const throw();
        };
};


std::ostream& operator<<(std::ostream&, const AForm&);

#endif