# pragma once
# include "Animal.hpp"

class Cat : public Animal
{
    private: 
        Brain   *brain;
    public:
        Cat();
        Cat(const Cat& d);
        Cat& operator=(const Cat& d);
        ~Cat();
        void    makeSound(void) const;
};