#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <limits>

typedef std::vector<int>::iterator it;

class Span
{
    private:
        unsigned int n;
        std::vector<int> vec;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& s);
        Span& operator=(const Span& s);
        ~Span();

        void addNumber(int);

        void add_rangeNumbers(it first, it last);

        void show(int n){
            for(int i = 0; i < n; i++){
                std::cout << "the element " << i << " is = " << vec[i] << '\n';
            }
        }

        class FullSpanException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        unsigned int shortestSpan();
        unsigned int longestSpan();
};

#endif