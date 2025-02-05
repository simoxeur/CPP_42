#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int32_t fx_p;
        static const int bits = 8;

    public:
    // constractors
        Fixed();
        Fixed( const int );
        Fixed ( const float );
    // copy constracor
        Fixed(const Fixed& obj);
    // copy operator (assign)
        Fixed& operator=(const Fixed& f);
    // destractor
        ~Fixed();
    // member functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif