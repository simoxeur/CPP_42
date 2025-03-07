#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
        ~ShrubberyCreationForm();

        void beSigned(const Bureaucrat&);
        void execute(Bureaucrat const & executor) const;

        // exception class fail to open file
        class FailToOpen : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

#endif
