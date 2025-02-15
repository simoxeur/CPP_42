#include "Character.hpp"

Character::Character(std::string name)
    : name(name)
{
    for(int i = 0; i < 4; i++)
        materia_slot[i] = NULL;
    for(int i = 0; i < 4; i++)
        garbage[i] = NULL;
}

Character::Character(const Character& c)
    : name(c.getName())
{
    for(int i = 0; i < 4; i++){
        if(c.materia_slot[i])
            materia_slot[i] = c.materia_slot[i]->clone();
        else
            materia_slot[i] = NULL;
    }
}

Character& Character::operator=(const Character& c)
{
    if (this != &c){
        name = c.getName();
        for(int i = 0; i < 4; i++){
            delete materia_slot[i];
            materia_slot[i] = NULL;
        }
        for(int i = 0; i < 4; i++){
            if (c.materia_slot[i])
                materia_slot[i] = c.materia_slot[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    for(int i = 0; i < 4; i++){
        delete materia_slot[i];
    }
    for(int i = 0; i < 4; i++){
        if(garbage[i])
            delete garbage[i];
    }
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    for(int i = 0; i < 4; i++){
        if (!materia_slot[i]){
            materia_slot[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4){
        for(int i = 0; i < 4; i++){
            if(!garbage[i]){
                garbage[i] = materia_slot[idx];
                break;
            }
        }
        materia_slot[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && materia_slot[idx])
        materia_slot[idx]->use(target);
}