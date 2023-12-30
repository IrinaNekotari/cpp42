#include "Fixed.hpp"


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
    this->setRawBits(f.getRawBits());
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
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void    Fixed::setRawBits(int const raw) 
{
    this->value = raw;
}