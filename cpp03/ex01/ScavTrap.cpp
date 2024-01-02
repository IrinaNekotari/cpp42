#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 50;
    this->ap = 20;
    std::cout << WHITE << "What is this ? The ClapTrap unit " << BLUE << BOLD
                << name << END << WHITE << " evolved into a ScavTrap !!!" << END
                << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << WHITE << "The ScavTrap " << RED << BOLD
                << this->name << END << WHITE << " has devolved back into a ScapTrap." << END
                << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->hp > 0 && this->ep > 0)
    {
        this->ep--;
        std::cout << WHITE << "The ScavTrap unit " << GREEN << BOLD
                    << this->name << END << WHITE << " launch a missile at " << RED << BOLD
                    << target << END << WHITE << " and inflicts "
                    << BOLD << YELLOW << this->ap << END << WHITE << " points of damage !"
                    << std::endl;
    }
    else if (this->hp <= 0)
    {
        std::cout << WHITE << "The ScavTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is destroyed, and cannot attack." << END
                    << std::endl;
    }
    else
    {
        std::cout << WHITE << "The ScavTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is out of power, and cannot attack." << END
                    << std::endl;
    }
}

void    ScavTrap::guardGate(void)
{
        if (this->hp > 0 && this->ep > 0)
    {
        this->ep--;
        std::cout << WHITE << "The ScavTrap unit " << GREEN << BOLD
                    << this->name << END << WHITE << " is now in GateKeeper mode." << END
                    << std::endl;
    }
    else if (this->hp <= 0)
    {
        std::cout << WHITE << "The ScavTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is destroyed, and cannot change mode." << END
                    << std::endl;
    }
    else
    {
        std::cout << WHITE << "The ScavTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is out of power, and cannot change mode." << END
                    << std::endl;
    }
}