#include "Fixed.hpp"

Fixed::Fixed( void ) :fx(0) {}

Fixed::Fixed( const int a )
{
    fx = a << bits;
}

Fixed::Fixed( const float a)
{
    // fx = round(a * (1 << bits));
    fx = static_cast<int>(a * (1 << bits) + (a >= 0.0f ? 0.5f : -0.5f));
}

Fixed::Fixed( const Fixed &f )
{
    this->fx = f.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &f)
{
    if (this != &f)
        this->fx = f.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
    out << f.toFloat();
    return out;
}

// the operator oberloads

bool Fixed::operator>(const Fixed &f) const
{
    return (fx > f.fx);
}

bool Fixed::operator<(const Fixed &f) const
{
    return (fx < f.fx);
}

bool Fixed::operator>=(const Fixed &f) const
{
    return (fx >= f.fx);
}

bool Fixed::operator<=(const Fixed &f) const
{
    return (fx <= f.fx);
}

bool Fixed::operator==(const Fixed &f) const
{
    return (fx == f.fx);
}

bool Fixed::operator!=(const Fixed &f) const
{
    return (fx != f.fx);
}

Fixed Fixed::operator+(const Fixed &f) const
{
    return Fixed(toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed &f) const
{
    return Fixed(toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed &f) const
{
    return Fixed(toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed &f) const
{
    return Fixed(toFloat() / f.toFloat());
}

Fixed& Fixed::operator++()
{
    fx++;
    return *this;
}

Fixed& Fixed::operator--()
{
    fx--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++fx;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --fx;
    return tmp;
}

// static member functions

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    if (f2.fx < f1.fx)
        return f2;
    return f1;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if (f2.fx < f1.fx)
        return f2;
    return f1;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if (f2.fx > f1.fx)
        return f2;
    return f1;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
    if (f2.fx > f1.fx)
        return f2;
    return f1;
}

// member functions

int Fixed::getRawBits( void ) const
{
    return fx;
}

void Fixed::setRawBits( int const raw)
{
    fx = raw;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(fx) / (1 << bits);
}

int Fixed::toInt( void ) const
{
    return fx >> bits;
}

Fixed::~Fixed() {}