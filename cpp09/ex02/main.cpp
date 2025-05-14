#include "PmergeMe.hpp"


bool containers_cmp(std::vector<int>& v, std::deque<int>& d)
{
    std::vector<int>::iterator v_it = v.begin();
    std::deque<int>::iterator d_it = d.begin();
    while(v_it != v.end() && d_it != d.end())
    {
        if(*d_it != *v_it)
            return false;
        v_it++;
        d_it++;
    }
    return true;
}

int main(int ac, char **av)
{
    if(ac <= 1)
    {
        std::cerr << "Bad input:\nset a list of positive numbers to sort\n";
        return 1;
    }
    try{
        PmergeMe* test = take_nbrs(av + 1, ac -1);
        test->print();

        // ----------------------------- sort and check -----------------------------

        // test->sort();
        // std::cout << (containers_cmp(test->get_vlist(), test->get_dlist()) ? "yes! the same\n" : "no? deferent\n");
        std::cout << (is_sorted<std::vector<int>, std::vector<int>::iterator>(test->get_vlist()) ? "yes! the vectors is sorted well\n" : "no? the vectors is not sorted\n");
        std::cout << (is_sorted<std::deque<int>, std::deque<int>::iterator>(test->get_dlist()) ? "yes! the deques is sorted well\n" : "no? the deques is not sorted\n");
        // std::cout << "vector:   ";
        // test->show_nbrs<std::vector<int>, std::vector<int>::iterator>(test->get_vlist().begin(), test->get_vlist().end());
        // std::cout << "deques:   ";
        // test->show_nbrs<std::deque<int>, std::deque<int>::iterator>(test->get_dlist().begin(), test->get_dlist().end());

        // --------------------------------------------------------------------------

        
        delete test;
    }
    catch(std::exception& execption){
        std::cerr << execption.what() << '\n';
    }
}