# pragma once
# include "AAnimal.hpp"

class Cat : public AAnimal
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