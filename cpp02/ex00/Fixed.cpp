#include "Fixed.hpp"

Fixed::Fixed() : fx_p(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    fx_p = f.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fx_p = f.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fx_p;
}

void Fixed::setRawBits( int raw)
{
    fx_p = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}