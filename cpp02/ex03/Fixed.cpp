#include "Fixed.hpp"

Fixed::Fixed() : fx_p(0) {}

Fixed::Fixed( int a )
{
    fx_p = a << bits;
}

Fixed::Fixed( float a )
{
    fx_p = static_cast<int>(a * (1 << bits) + (a > 0.0f ? 0.5f : -0.5f));
}

Fixed::Fixed(const Fixed& f)
{
    fx_p = f.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& f)
{
    if (this != &f)
        this->fx_p = f.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
    out << f.toFloat();
    return out;
}

// operators overloads

bool Fixed::operator>(const Fixed& f) const
{
    return (this->fx_p > f.fx_p);
}

bool Fixed::operator<(const Fixed& f) const
{
    return (this->fx_p < f.fx_p);
}

bool Fixed::operator>=(const Fixed& f) const
{
    return (this->fx_p >= f.fx_p);
}

bool Fixed::operator<=(const Fixed& f) const
{
    return (this->fx_p <= f.fx_p);
}

bool Fixed::operator==(const Fixed& f) const
{
    return (this->fx_p == f.fx_p);
}

bool Fixed::operator!=(const Fixed& f) const
{
    return (this->fx_p != f.fx_p);
}

Fixed Fixed::operator+(const Fixed& f) const
{
    return Fixed(this->toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed& f) const
{
    return Fixed(this->toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed& f) const
{
    return Fixed(this->toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed& f) const
{
    return Fixed(this->toFloat() / f.toFloat());
}

Fixed& Fixed::operator++()
{
    this->fx_p++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->fx_p--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->fx_p++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->fx_p--;
    return tmp;
}

int Fixed::getRawBits( void ) const
{
    return fx_p;
}

void Fixed::setRawBits( int raw)
{
    fx_p = raw;
}

int Fixed::toInt( void ) const
{
    return fx_p >> bits;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(fx_p) / (1 << bits);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a.fx_p > b.fx_p ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a.fx_p > b.fx_p ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a.fx_p < b.fx_p ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a.fx_p < b.fx_p ? a : b);
}

Fixed::~Fixed() {}