#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++){
        materia_lst[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& m)
{
    for(int i = 0; i < 4; i++){
        if(m.materia_lst[i])
            materia_lst[i] = m.materia_lst[i]->clone();
        else
            materia_lst[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& m)
{
    if (this != &m)
    {
        for(int i = 0; i < 4; i++){
            delete materia_lst[i];
            materia_lst[i] = NULL;
        }
        for(int i = 0; i < 4; i++){
            if (m.materia_lst[i])
                materia_lst[i] = m.materia_lst[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++){
        if (materia_lst[i])
            delete materia_lst[i];
    }
}

void MateriaSource::learnMateria(AMateria* am)
{
    if(!am)
        return;
    for(int i = 0; i < 4; i++){
        if(!materia_lst[i]){
            materia_lst[i] = am;
            // materia_lst[i] = am->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for(int i = 0; i < 4; i++){
        if(materia_lst[i] && materia_lst[i]->getType() == type){
            return materia_lst[i]->clone();
        }
    }
    return NULL;
}