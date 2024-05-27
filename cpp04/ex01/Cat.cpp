# include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "A cat has appeared." << std::endl;
    this->Animal::type = "Cat";
    this->brain = new Brain();
}

Cat::~Cat()
{
    std::cout << "The cat is gone." << std::endl;
    delete(this->brain);
}

Cat::Cat(const Cat& d) : Animal()
{
    (*this) = d;
}

Cat& Cat::operator=(const Cat& c)
{
    std::cout << "The cat is cloned." << std::endl;
    this->type = c.type;
    this->brain = new Brain(*c.brain);
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "The cat goes *MEOOOOW*." << std::endl;
}