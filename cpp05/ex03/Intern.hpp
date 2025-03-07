#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// #include "AForm.hpp"

class AForm;

class Intern
{
    private:
        AForm* createShrubberyCreationForm(std::string target);
        AForm* createRobotomyRequestForm(std::string target);
        AForm* createPresidentialPardonForm(std::string target);
        typedef AForm* (Intern::*mf_ptr)(std::string);
        static mf_ptr listForms[3];

    public:
        Intern();
        Intern(const Intern&);
        Intern& operator=(const Intern&);
        ~Intern();

        AForm* makeForm(std::string, std::string);
};

#endif