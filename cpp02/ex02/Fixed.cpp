#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->value = 0;
}

/**
* Constructeur par copie. Il prends en argument un autre objet, et
* copie ce dernier dans notre nouvel objet. 
*/
Fixed::Fixed(const Fixed& f)
{
    (*this) = f;
}

Fixed::Fixed(const int i)
{
    this->value = i << this->bits;
}

Fixed::Fixed(const float f)
{
    this->value = roundf(f * (1 << this->bits));
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const 
{
    return this->value;
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

/**
* On surchage l'opérateur =, c'est a dire on redéfinit ce que =
* veut dire pour notre objet.
* Il est possible de redéfinir tous les opérateurs tels que <, ++, ==, etc 
*/
Fixed& Fixed::operator=(const Fixed& f)
{
     if (this != &f)
        this->value = f.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &f)
{
    return (this->value > f.getRawBits());
}

bool Fixed::operator<(const Fixed &f)
{
    return (this->value < f.getRawBits());
}

bool Fixed::operator<=(const Fixed &f)
{
    return (this->value <= f.getRawBits());
}

bool Fixed::operator>=(const Fixed &f)
{
    return (this->value >= f.getRawBits());
}

bool Fixed::operator==(const Fixed &f)
{
    return (this->value == f.getRawBits());
}

bool Fixed::operator!=(const Fixed &f)
{
    return (this->value != f.getRawBits());
}

Fixed Fixed::operator+(const Fixed &f)
{
    return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed Fixed::operator-(const Fixed &f)
{
    return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed Fixed::operator*(const Fixed &f)
{
    return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed Fixed::operator/(const Fixed &f)
{
    if (f.toFloat() == 0)
    {
        std::cout << "ERROR : Divided by  !" << std::endl;
        return (Fixed(this->toFloat()));
    }
    return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed&   Fixed::operator++(void) {
    ++this->value;
    return (*this);
}

Fixed   Fixed::operator++(int) {
    Fixed tmp(*this);
    tmp.value = this->value++;
    return (tmp);
}

Fixed& Fixed::operator--(void) {
    --this->value;
    return (*this);
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    tmp.value = this->value--;
    return (tmp);
}

Fixed& Fixed::min( Fixed &a, Fixed &b ) 
{
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) 
{
    if ( a.getRawBits() < b.getRawBits() )
        return a;
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) 
{
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b ) 
{
    if ( a.getRawBits() > b.getRawBits() )
        return a;
    return b;
}