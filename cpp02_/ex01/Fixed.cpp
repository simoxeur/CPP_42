#include "Fixed.hpp"

Fixed::Fixed() : fx_p(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int a )
{
    std::cout << "Int constructor called" << std::endl;
    fx_p = a << bits;
}

Fixed::Fixed( float a )
{
    std::cout << "Float constructor called" << std::endl;
    fx_p = static_cast<int>(a * (1 << bits) + (a > 0.0f ? 0.5f : -0.5f));
}

Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    fx_p = f.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->fx_p = f.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
    out << f.toFloat();
    return out;
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

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}