#include "Fixed.hpp"

Fixed::Fixed( void ) :fx(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int a )
{
    fx = a << bits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float a)
{
    fx = round(a * (1 << bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &f )
{
    std::cout << "Copy constructor called" << std::endl;
    this->fx = f.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f)
        this->fx = f.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& f)
{
    out << f.toFloat();
    return out;
}


int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
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

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}