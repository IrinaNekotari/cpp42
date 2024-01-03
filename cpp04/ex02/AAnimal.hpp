# pragma once
# include <iostream>
# include "Brain.hpp"

class AAnimal
{
    protected:
        std::string     type;
    public:
        AAnimal();
        AAnimal(const AAnimal& a);
        virtual ~AAnimal();
        AAnimal& operator=(const AAnimal& a);
        virtual void makeSound(void) const = 0;
        std::string  getType(void) const;
};