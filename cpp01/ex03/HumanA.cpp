#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{}

HumanA::~HumanA()
{
    std::cout << this->name << " just died like that. May he rest in peace." << std::endl;
}

void    HumanA::attack(void) const
{
    if (this->weapon.getType() == "")
        std::cout << this->name << " doesn't have a weapon and cannot attack." <<std::endl;
    else    
        std::cout << this->name << " attacks with their " << this->weapon.getType() << "." <<std::endl;
}