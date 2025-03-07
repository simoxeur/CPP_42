#include "Base.hpp"

Base::~Base(){}

Base* generate(void)
{
    srand(time(0));
    int r = rand() % 3;

    Base* ourBase = NULL;
    switch (r)
    {
    case 0:
        ourBase = new A;
        break;
    case 1:
        ourBase = new B;
        break;
    case 2:
        ourBase = new C;
        break;

    default:
        break;
    }
    return ourBase;
}

void    identify(Base* p)
{
    A* Aptr = dynamic_cast<A*>(p);
    B* Bptr = dynamic_cast<B*>(p);
    C* Cptr = dynamic_cast<C*>(p);
    if (Aptr)
        std::cout << "using pointer   => this an A object" << std::endl;
    if (Bptr)
        std::cout << "using pointer   => this an B object" << std::endl;
    if (Cptr)
        std::cout << "using pointer   => this an C object" << std::endl;
}

void    identify(Base& p)
{
    try{
        A& Aref = dynamic_cast<A&>(p);
        std::cout << "using reference => this an A object" << std::endl;
        (void)Aref;
    }
    catch(std::bad_cast&){
        try{
            B& Bref = dynamic_cast<B&>(p);
            std::cout << "using reference => this an B object" << std::endl;
            (void)Bref;
        }
        catch(std::bad_cast&){
            std::cout << "using reference => this an C object" << std::endl;
        }
    }
}