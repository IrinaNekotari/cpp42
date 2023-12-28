# include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon(void)
{
    std::cout << this->type << " got destroyed by a divine beam of light." << std::endl;
}


void Weapon::setType(std::string type)
{
    this->type = type;
}

std::string Weapon::getType(void)
{
    return (this->type);
}