#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&){return *this;}

Intern::~Intern(){}

AForm* Intern::createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

Intern::mf_ptr Intern::listForms[3] = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

std::string convertToCamelCase(std::string &s)
{
    std::string res = "";
    bool sp = true;
    for(std::size_t i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            while(s[i] == ' ')
                i++;
            sp = true;
        }
        (sp ? res += std::toupper(s[i]) : res += std::tolower(s[i]));
        sp = (s[i] != ' ' ? false : sp);
    }
    return res;
}

int findForm(std::string name)
{
    std::string typeForm = convertToCamelCase(name) + "Form";
    int id = (typeForm == "ShrubberyCreationForm") * 1 + (typeForm == "RobotomyRequestForm") * 2 + (typeForm == "PresidentialPardonForm") * 3 - 1;
    if(id == -1)
        throw "not exist";
    return id;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    int id = -1;
    AForm* res = NULL;
    try
    {
        id = findForm(name);
        res = (this->*listForms[id])(target);
        std::cout << "Intern creates " << convertToCamelCase(name) + "Form" << '\n';
    }
    catch(const char * msg)
    {
        std::cout << name << " " << msg << '\n';
    }
    return res;
}
