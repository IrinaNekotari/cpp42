# include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "A dog has appeared." << std::endl;
    this->Animal::type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "The dog is gone." << std::endl;
    delete(this->brain);
}

Dog::Dog(const Dog& d) : Animal()
{
    (*this) = d;
}

Dog& Dog::operator=(const Dog& d)
{
    std::cout << "The dog is cloned." << std::endl;
    this->type = d.type;
    this->brain = new Brain(*d.brain);
    return (*this);
}

void Dog::makeSound(void) const
{
    std::cout << "The dog goes *WOOF*." << std::endl;
}