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
        void   setRawBits(int const raw);
        int    getRawBits(void) const;
        float  toFloat(void) const;
        int    toInt(void) const;
};

std::ostream & operator<<(std::ostream &o, Fixed const &i);