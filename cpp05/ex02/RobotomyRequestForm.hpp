#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <bits/stdc++.h>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm&);
        RobotomyRequestForm& operator=(const RobotomyRequestForm&);
        ~RobotomyRequestForm();

        void beSigned(const Bureaucrat&);
        void execute(Bureaucrat const & executor) const;
};

#endif
