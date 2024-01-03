# include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout << "A strange, unknown animal has appeared." << std::endl;
    this->type = "???";
}

AAnimal::~AAnimal()
{
    std::cout << "The strange, unknown animal is gone." << std::endl;
}

AAnimal::AAnimal(const AAnimal& a)
{
    (*this) = a;
    std::cout << "Copy constructor applied to the unknown animal." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& a)
{
    this->type = a.type;
    return (*this);
}

void AAnimal::makeSound(void) const
{
    std::cout << "*Eldritch noises*" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}