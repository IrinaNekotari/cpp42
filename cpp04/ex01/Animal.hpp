# pragma once
# include <iostream>
# include "Brain.hpp"

class Animal
{
    protected:
        std::string     type;
    public:
        Animal();
        Animal(const Animal& a);
        virtual ~Animal();
        Animal& operator=(const Animal& a);
        virtual void makeSound(void) const;
        std::string  getType(void) const;
};