#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
    private:
        int fx;
        static const int bits = 8;

    public:
        // constractor and copy constractor
        Fixed( void );
        Fixed( const int a);
        Fixed( const float a);
        Fixed(const Fixed &f);
        // copy assignment operator
        Fixed &operator =(const Fixed &f);
        friend std::ostream& operator<<(std::ostream& out, const Fixed& f);
        // destractor
        ~Fixed();
        // member functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

#endif