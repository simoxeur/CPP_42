#include "MutantStack.tpp"

int main()
{
    MutantStack<int> mstack;
    
    for(int i = 0; i < 20; i++){
        mstack.push(i);
    }
    std::size_t size = mstack.size();

    // creating a copy stack
    MutantStack<int> cpstack(mstack);
    std::size_t cpsize = cpstack.size();

    std::cout << "the size of mstack = " << size << '\n';

    std::cout << "\n------printing the values using top pop ------\n";

    for(std::size_t i = 0; i < size; i++){
        std::cout << mstack.top() << "  ";
        mstack.pop();
    }
    std::cout << '\n';

    std::cout << "\nthe size of cptack = " << cpsize << '\n';

    std::cout << "\n------printing the values using iterators ------\n";


    MutantStack<int>::iterator it = cpstack.begin();
    MutantStack<int>::iterator ite = cpstack.end();

    --ite;

    while (it <= ite)
    {
        std::cout << *ite << "  ";
        --ite;
    }
    std::cout << '\n';
    return 0;
}