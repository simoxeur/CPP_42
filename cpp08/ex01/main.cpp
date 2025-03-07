#include "Span.hpp"

int main()
{
    try{
        std::vector<int> vec;
        vec.push_back(6);
        vec.push_back(3);
        vec.push_back(17);
        vec.push_back(9);
        vec.push_back(11);


        Span sp = Span(5);
        sp.add_rangeNumbers(vec.begin(), vec.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

    }
    catch(std::exception& e){
        std::cout << e.what() << '\n';
    }
}