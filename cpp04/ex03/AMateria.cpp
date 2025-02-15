#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
    : type(type) {}

AMateria::AMateria(const AMateria& a)
    : type(a.type) {}

AMateria& AMateria::operator=(const AMateria& a)
{
    (void)a;
    return *this;
}

AMateria::~AMateria(){}

std::string const& AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
}