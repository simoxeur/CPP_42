#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

// class ICharacter;

class AMateria
{
    protected:
        const std::string type;

    public:
        AMateria(std::string const & type);
        AMateria(const AMateria&);
        AMateria& operator=(const AMateria&);
        virtual ~AMateria();

        std::string const & getType() const; // return the materia type

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif