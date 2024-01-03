# include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "A dog has appeared." << std::endl;
    this->Animal::type = "Dog";
}

Dog::~Dog()
{
    std::cout << "The dog is gone." << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "The dog goes *WOOF*." << std::endl;
}