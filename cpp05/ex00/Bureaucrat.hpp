#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const   std::string name;
        int     grade;
    
    public:
        Bureaucrat();
        Bureaucrat(std::string, int);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        ~Bureaucrat();

        std::string get_name(void) const;
        int get_grade(void) const;
        Bureaucrat operator++(int);
        Bureaucrat operator--(int);

        // exexption class
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




std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif