# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "A strange, unknown WrongAnimal has appeared." << std::endl;
    this->type = "???";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "The strange, unknown WrongAnimal is gone." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a)
{
    (*this) = a;
    std::cout << "Copy constructor applied to the unknown WrongAnimal." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
    this->type = a.type;
    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "*Eldritcher noises*" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}