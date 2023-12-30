#pragma once
#include <iostream>

class Fixed {
    private: 
        int                 value;
        const static int    bits = 8;
    public:
        Fixed();
        Fixed(const Fixed& f);
        ~Fixed();
        Fixed& operator=(const Fixed& f);
        int    getRawBits(void) const;
        void   setRawBits(int const raw);
};