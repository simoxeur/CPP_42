#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructed" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructed" << std::endl;
}

Brain::Brain(const Brain& b)
{
    std::cout << "Brain copied" << std::endl;
    *this = b;
}

Brain& Brain::operator=(const Brain& b)
{
    if (this != &b)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = b.ideas[i];
        }
    }
    return *this;
}