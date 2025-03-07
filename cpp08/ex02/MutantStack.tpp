#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& org)
    : std::stack<T, Container>(org) {}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& org)
{
    if(this != &org)
        std::stack<T, Container>::operator=(org);
    return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}