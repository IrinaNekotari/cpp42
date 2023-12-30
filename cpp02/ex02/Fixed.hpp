# pragma once
# include <iostream>
# include <cmath>

class Fixed {
    private: 
        int                 value;
        const static int    bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& f);
        Fixed(const int i);
        Fixed(const float f);
        ~Fixed();
        Fixed& operator=(const Fixed& f);
        bool operator<=(const Fixed& f);
        bool operator>=(const Fixed& f);
        bool operator<(const Fixed& f);
        bool operator>(const Fixed& f);
        bool operator==(const Fixed& f);
        bool operator!=(const Fixed& f);
        Fixed operator+(const Fixed& f);
        Fixed operator-(const Fixed& f);
        Fixed operator*(const Fixed& f);
        Fixed operator/(const Fixed& f);
        Fixed& operator++(void);
        Fixed  operator++(int);
        Fixed& operator--(void);
        Fixed  operator--(int);

        void   setRawBits(int const raw);
        int    getRawBits(void) const;
        float  toFloat(void) const;
        int    toInt(void) const;
        static Fixed&       min(Fixed &a, Fixed &b);
        static Fixed&       max(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);