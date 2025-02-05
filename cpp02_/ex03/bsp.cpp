#include "Point.hpp"

float area(Point const& A, Point const& B, Point const& C)
{
    return std::fabs(
        A.get_x().toFloat() * (B.get_y().toFloat() - C.get_y().toFloat()) +
        B.get_x().toFloat() * (C.get_y().toFloat() - A.get_y().toFloat()) +
        C.get_x().toFloat() * (A.get_y().toFloat() - B.get_y().toFloat())
    ) / 2.0;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float ar = area(a, b, c);
    float ar1 = area(point, a, b);
    float ar2 = area(point, b, c);
    float ar3 = area(point, a, c);
    return ((ar1> 0) && (ar2 > 0) && (ar3 > 0) && std::fabs(ar - (ar1 + ar2 + ar3)) < 0.000001);
}