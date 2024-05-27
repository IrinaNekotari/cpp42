#include "Fixed.hpp"

int main(void) {

    Fixed        a;
    Fixed const  b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << "Tests autres operateurs" << std::endl;
    Fixed c(5);
    Fixed d(0);
    Fixed e(0);
    std::cout << (a - c) << std::endl;
    std::cout << (a + c) << std::endl;
    std::cout << (a * c) << std::endl;
    std::cout << (a / c) << std::endl;
    std::cout << (a / d) << std::endl;
    std::cout << (a == c) << std::endl;
    std::cout << (d == e) << std::endl;
    std::cout << (a != c) << std::endl;
    std::cout << (a >= c) << std::endl;
    std::cout << (a <= c) << std::endl;
    std::cout << (a < c) << std::endl;
    std::cout << (a > c) << std::endl;
    return (0);
}