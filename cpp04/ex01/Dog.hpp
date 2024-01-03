# pragma once
# include "Animal.hpp"

class Dog : public Animal
{
    private: 
        Brain   *brain;
    public:
        Dog();
        Dog(const Dog& d);
        Dog& operator=(const Dog& d);
        ~Dog();
        void    makeSound(void) const;
};