#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int32_t fx_p;
        static const int bits = 8;

    public:
        Fixed();
        Fixed(const Fixed& obj);
        Fixed& operator=(const Fixed& f);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif