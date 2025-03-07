#include "Span.hpp"

std::vector<int> generate_randvec(std::size_t size)
{
    std::vector<int> vec;
    vec.reserve(size);
    srand(time(0));
    for(std::size_t i = 0; i < size; i++){
        vec.push_back(rand() % size);
    }
    return vec;
}

int main()
{
    try{
        std::size_t size = 15000;
        std::vector<int> ran_vec = generate_randvec(size);
        Span spn(size);
        spn.add_rangeNumbers(ran_vec.begin(), ran_vec.end());
        spn.print();
        std::cout << "size = " << spn.size() << '\n';

        std::cout << "\n------ longest and shortest span ------" << '\n';
        std::cout << "longest -----> " << spn.longestSpan() << '\n';
        std::cout << "shortest -----> " << spn.shortestSpan() << '\n';


        /*
        int arr[5] = {6, 3, 17, 9, 11};
        std::vector<int> vec(arr, arr + 5);


        Span sp = Span(5);
        // sp.add_rangeNumbers(vec.begin(), vec.end());
        sp.add_rangeNumbers(arr, arr + 5);
        sp.print();
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        */
    }
    catch(std::exception& e){
        std::cout << e.what() << '\n';
    }
}