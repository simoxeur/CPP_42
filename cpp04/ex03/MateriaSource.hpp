#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* materia_lst[4];

    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource&);
        MateriaSource& operator=(const MateriaSource&);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif