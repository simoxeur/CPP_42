#include "Span.hpp"

Span::Span() : n(0) {}

Span::Span(unsigned int N) : n(N)
{
    vec.reserve(n);
}

Span::Span(const Span& s)
{
    *this = s;
}

Span& Span::operator=(const Span& s)
{
    if(this != &s){
        n = s.n;
        vec = s.vec;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int number)
{
    if(vec.size() >= n)  // check if should use >
        throw FullSpanException();
    vec.push_back(number);
}

void Span::add_rangeNumbers(it first, it last)
{
    size_t range_size = std::distance(first, last);

    if (vec.size() + range_size > n) 
        throw FullSpanException();
    vec.insert(vec.end(), first, last);
}

void Span::add_rangeNumbers(int* first, int* last)
{
    size_t range_size = std::distance(first, last);

    if (vec.size() + range_size > n) 
        throw FullSpanException();
    for (int* ptr = first; ptr != last; ++ptr) {
        vec.push_back(*ptr);
    }
}

unsigned int Span::shortestSpan()
{
    if(vec.size() < 2)
        throw NoSpanException();

    std::sort(vec.begin(), vec.end());
    unsigned int minSpan(std::numeric_limits<unsigned int>::max()), curSpan(0);
    
    for(unsigned int i = 0; i < vec.size() - 1; i++){
        curSpan = vec[i + 1] - vec[i];
        if(curSpan < minSpan)
            minSpan = curSpan;
    }
    return minSpan;
}

unsigned int Span::longestSpan()
{
    if(vec.size() < 2)
    throw NoSpanException();
    
    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());
    
    return static_cast<unsigned int>(max - min);
}

void Span::print()
{
    for(it it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << "  ";
    }
    std::cout << std::endl;
}

unsigned int Span::size()
{
    return n;
}

const char* Span::FullSpanException::what() const throw()
{
    return "The span is full";
}

const char* Span::NoSpanException::what() const throw()
{
    return "No span exist";
}
