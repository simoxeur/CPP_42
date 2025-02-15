#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
    : AMateria("cure") {}

Cure::Cure(const Cure& a)
    : AMateria(a.getType()) {}

Cure& Cure::operator=(const Cure& a)
{
    (void)a;
    return *this;
}

Cure::~Cure(){}

Cure* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}