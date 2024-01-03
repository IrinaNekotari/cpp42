# include "Dog.hpp"

Dog::Dog() : AAnimal()
{
    std::cout << "A dog has appeared." << std::endl;
    this->AAnimal::type = "Dog";
    this->brain = new Brain();
}

Dog::~Dog()
{
    std::cout << "The dog is gone." << std::endl;
    delete(this->brain);
}

Dog::Dog(const Dog& d) : AAnimal()
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