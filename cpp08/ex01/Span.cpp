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
    if(vec.size() >= n)
        throw FullSpanException();
    vec.push_back(number);
}

void Span::add_rangeNumbers(it first, it last)
{
    size_t range_size = std::distance(first, last);

    if (vec.size() + range_size > n) 
        throw FullSpanException();
    for (it it = first; it != last; ++it) {
        vec.push_back(*it);
    }
}

// template <typename iterartor>
// void Span::add_rangeNumbers(iterartor first, iterartor last)
// {
//     size_t range_size = std::distance(first, last);
//     if (vec.size() + range_size > n)
//         throw FullSpanException();
//     vec.reserve(vec.size() + range_size);
//     for(iterartor it = first; it != last; it++){
//         vec.push_back(*it);
//     }
// }


unsigned int Span::shortestSpan()
{
    unsigned int minSpan(std::numeric_limits<unsigned int>::max()), curSpan(0);
    if(vec.size() < 2)
        throw NoSpanException();
    std::sort(vec.begin(), vec.end());
    for(unsigned int i = 0; i < n - 1; i++){
        curSpan = vec[i + 1] - vec[i];
        if(curSpan < minSpan)
            minSpan = curSpan;
    }
    return minSpan;
}

unsigned int Span::longestSpan()
{
    unsigned int longSpan(0);
    int min = *std::min_element(vec.begin(), vec.end());
    int max = *std::max_element(vec.begin(), vec.end());
    longSpan = static_cast<unsigned int>(max - min);
    return longSpan;
}

const char* Span::FullSpanException::what() const throw()
{
    return "out of range";
}

const char* Span::NoSpanException::what() const throw()
{
    return "No span exist";
}