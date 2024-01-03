# pragma once
# include "AAnimal.hpp"

class Dog : public AAnimal
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