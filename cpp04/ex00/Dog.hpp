# pragma once
# include "Animal.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        ~Dog();
        void    makeSound(void) const;
};