# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "A WrongCat has appeared." << std::endl;
    this->WrongAnimal::type = "WrongCat";
}

WrongCat::~WrongCat()
{
    std::cout << "The WrongCat is gone." << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "The WrongCat goes *MEOOOOW*." << std::endl;
}