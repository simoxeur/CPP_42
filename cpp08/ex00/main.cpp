#include "easyfind.tpp"

int main()
{
    int to_found = 5;
    std::vector<int> v;
    v.push_back(7);
    v.push_back(5);
    v.push_back(13);
    v.push_back(21);
    v.push_back(18);
    std::deque<int> dq;
    dq.push_back(13);
    dq.push_back(21);
    dq.push_back(100);
    dq.push_back(5);
    dq.push_back(18);
    dq.pop_front();
    std::vector<int>::iterator it = easyfind(v, to_found);
    if(it != v.end())
        std::cout << "in vector found in " << std::distance(v.begin(), it) << '\n';
    std::deque<int>::iterator d_it = easyfind(dq, to_found);
    if(d_it != dq.end())
        std::cout << "int deque found in " << std::distance(dq.begin(), d_it) << '\n';
}