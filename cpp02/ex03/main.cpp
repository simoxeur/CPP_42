#include "Point.hpp"

int main()
{
    Point a(4, 6);
    Point b(2, 1);
    Point c(7, 5);

    Point p(3.5, 4);

    if (bsp(a, b, c, p) == true)
        std::cout << "Yes!!! the point is inside the trinagle\n";
    else
        std::cout << "No!!! the point is outside the point\n";

    return 0;
}
