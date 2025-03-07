#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <algorithm>


template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        typedef typename Container::iterator iterator;
        MutantStack();
        MutantStack(const MutantStack&);
        MutantStack& operator=(const MutantStack& );
        ~MutantStack();
        iterator begin();
        iterator end();
};


#endif
