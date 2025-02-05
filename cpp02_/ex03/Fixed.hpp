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
    // oberload operators
        bool operator>(const Fixed& f) const;
        bool operator<(const Fixed& f) const;
        bool operator>=(const Fixed& f) const;
        bool operator<=(const Fixed& f) const;
        bool operator==(const Fixed& f) const;
        bool operator!=(const Fixed& f) const;
        Fixed operator+(const Fixed& f) const;
        Fixed operator-(const Fixed& f) const;
        Fixed operator*(const Fixed& f) const;
        Fixed operator/(const Fixed& f) const;
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

    // destractor
        ~Fixed();
    // member functions
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
    // static member functions
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& f);

#endif