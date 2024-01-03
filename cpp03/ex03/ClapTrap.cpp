#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hp = 10;
    this->ep = 10;
    this->ap = 0;
    std::cout << WHITE << "The ClapTrap unit " << BLUE << BOLD
                << name << END << WHITE << " has been created !" << END
                << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& c)
{
   (*this) = c;
   std::cout << WHITE << "(Through copy constructor)" << END << std::endl;
}

ClapTrap::~ClapTrap()
{
        std::cout << WHITE << "The ClapTrap unit " << RED << BOLD
                << this->name << END << WHITE << " has been destroyed !" << END
                << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
    this->name = c.name;
    this->hp = c.hp;
    this->ep = c.ep;
    this->ap = c.ap;
        this->name = name;
    std::cout << WHITE << "The ClapTrap unit " << BLUE << BOLD
                << this->name << END << WHITE << " has been cloned !" << END
                << std::endl;
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->hp > 0 && this->ep > 0)
    {
        this->ep--;
        std::cout << WHITE << "The ClapTrap unit " << GREEN << BOLD
                    << this->name << END << WHITE << " attacks " << RED << BOLD
                    << target << END << WHITE << " and inflicts "
                    << BOLD << YELLOW << this->ap << END << WHITE << " points of damage !"
                    << std::endl;
    }
    else if (this->hp <= 0)
    {
        std::cout << WHITE << "The ClapTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is destroyed, and cannot attack." << END
                    << std::endl;
    }
    else
    {
        std::cout << WHITE << "The ClapTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is out of power, and cannot attack." << END
                    << std::endl;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->hp -= amount;
    std::cout << WHITE << "The ClapTrap unit " << GREEN << BOLD
                << this->name << END << WHITE << " takes " << RED << BOLD
                << amount << END << WHITE << " points of damage !"
                << std::endl;
    if (this->hp <= 0)
    {
        std::cout << WHITE << "This was a lethal hit !" << std::endl;
        std::cout << WHITE << "The ClapTrap unit " << PURPLE << BOLD
                << this->name << END << WHITE << " is " << RED << BOLD
                << "dead" << END << WHITE << " !!!"
                << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hp > 0 && this->ep > 0)
    {
        this->ep--;
        std::cout << WHITE << "The ClapTrap unit " << GREEN << BOLD
                    << this->name << END << WHITE << " repairs itself for " << GREEN << BOLD
                    << amount << END << WHITE << " points." << END
                    << std::endl;
        this->hp += amount;
    }
    else if (this->hp <= 0)
    {
        std::cout << WHITE << "The ClapTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is destroyed, and cannot repair itself." << END
                    << std::endl;
    }
    else
    {
        std::cout << WHITE << "The ClapTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is out of power, and cannot repair itself." << END
                    << std::endl;
    }
}