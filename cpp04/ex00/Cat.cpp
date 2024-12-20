# include "Cat.hpp"

Cat::Cat() : AAnimal()
{
    std::cout << "A cat has appeared." << std::endl;
    this->AAnimal::type = "Cat";
}

Cat::~Cat()
{
    std::cout << "The cat is gone." << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "The cat goes *MEOOOOW*." << std::endl;
}