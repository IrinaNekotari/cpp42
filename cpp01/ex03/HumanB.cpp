#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout << this->name << " just died like that. May he rest in pieces." << std::endl;
}

void    HumanB::setWeapon( Weapon& weapon ) {
    this->weapon = &weapon;
    std::cout << this->name << " picked up a " << weapon.getType() << " !" << std::endl;
}

void    HumanB::attack(void) const
{
    if (this->weapon == NULL)
        std::cout << this->name << " throws a mean hook !" <<std::endl;
    else    
        std::cout << this->name << " attacks with their " << this->weapon->getType() << "." <<std::endl;
}