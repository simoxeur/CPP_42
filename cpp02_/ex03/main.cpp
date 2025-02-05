#include "Point.hpp"

void test_bsp(Point const a, Point const b, Point const c, Point const point, bool expected)
{
    bool result = bsp(a, b, c, point);
    std::cout << "Expected: " << expected << ", Result: " << result << "\n";
}

int main()
{
    Point a(0, 0);
    Point b(4, 0);
    Point c(2, 4);

    Point p(1, 1);

    if (bsp(a, b, c, p) == true)
        std::cout << "yes\n";
    else
        std::cout << "noo\n";

    return 0;
}
