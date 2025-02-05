#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <cmath>

class Point
{
    private:
        const Fixed x;
        const Fixed y;

    public:
        Point();
        Point( const float, const float );
        Point( const Point& );
        Point& operator=(const Point& );
        const Fixed& get_x(void) const;
        const Fixed& get_y(void) const;
        ~Point();

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif