# pragma once
# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal& src);
        WrongAnimal& operator=(const WrongAnimal& a);
        void        makeSound(void) const;
        std::string getType(void) const; 
};