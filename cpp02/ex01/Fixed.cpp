#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

/**
* Constructeur par copie. Il prends en argument un autre objet, et
* copie ce dernier dans notre nouvel objet. 
*/
Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    (*this) = f;
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = i << this->bits;
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(f * (1 << this->bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

/**
* On surchage l'opérateur =, c'est a dire on redéfinit ce que =
* veut dire pour notre objet.
* Il est possible de redéfinir tous les opérateurs tels que <, ++, ==, etc 
*/
Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
     if (this != &f)
        this->value = f.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const 
{
    return (this->value);
}

void    Fixed::setRawBits(int const raw) 
{
    this->value = raw;
}

int     Fixed::toInt(void) const
{
    return (this->value >> this->bits);
}

float   Fixed::toFloat(void) const
{
    return ((float)(this->getRawBits()) / (1 << this->bits));
}

std::ostream & operator<<(std::ostream &o, Fixed const &i) 
{
    o << i.toFloat();
    return o;
}