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
        // operatorts overloads
        friend std::ostream& operator<<(std::ostream& out, const Fixed& f);
        bool operator>(const Fixed &f) const;
        bool operator<(const Fixed &f) const;
        bool operator>=(const Fixed &f) const;
        bool operator<=(const Fixed &f) const;
        bool operator==(const Fixed &f) const;
        bool operator!=(const Fixed &f) const;
        Fixed operator+(const Fixed &f) const;
        Fixed operator-(const Fixed &f) const;
        Fixed operator*(const Fixed &f) const;
        Fixed operator/(const Fixed &f) const;
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);

        // destractor
        ~Fixed();

        // member functions
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

        // static member functions
        static Fixed& min(Fixed& f1, Fixed& f2);
        static const Fixed& min(const Fixed& f1, const Fixed& f2);
        static Fixed& max(Fixed& f1, Fixed& f2);
        static const Fixed& max(const Fixed& f1, const Fixed& f2);

};

#endif