# include "Animal.hpp"

Animal::Animal()
{
    std::cout << "A strange, unknown animal has appeared." << std::endl;
    this->type = "???";
}

Animal::~Animal()
{
    std::cout << "The strange, unknown animal is gone." << std::endl;
}

Animal::Animal(const Animal& a)
{
    (*this) = a;
    std::cout << "Copy constructor applied to the unknown animal." << std::endl;
}

Animal& Animal::operator=(const Animal& a)
{
    this->type = a.type;
    return (*this);
}

void Animal::makeSound(void) const
{
    std::cout << "*Eldritch noises*" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}