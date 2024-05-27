# include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hp = 100;
    this->ep = 100;
    this->ap = 30;
    std::cout << WHITE << "Oh no, what now ? The ClapTrap unit " << BLUE << BOLD
                << name << END << WHITE << " evolved into a FragTrap !!!" << END
                << std::endl;
}

FragTrap::~FragTrap()
{
        std::cout << WHITE << "The FragTrap " << RED << BOLD
                << this->name << END << WHITE << " has devolved back into a ScapTrap. Good riddance." << END
                << std::endl;
}

FragTrap::FragTrap(const FragTrap& f) : ClapTrap(f.name)
{
    (*this) = f;
}

FragTrap& FragTrap::operator=(const FragTrap& f)
{
    this->ap = f.ap;
    this->ep = f.ep;
    this->hp = f.hp;
    this->name = f.name;
    return (*this);
}


void    FragTrap::highFivesGuys(void)
{
    if (this->hp > 0 && this->ep > 0)
    {
        this->ep--;
        std::cout << WHITE << "The ScavTrap unit " << GREEN << BOLD
                    << this->name << END << WHITE << " highfives everyone !" << END
                    << std::endl;
    }
    else if (this->hp <= 0)
    {
        std::cout << WHITE << "The ScavTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is destroyed, and cannot high five. This is so sad :(" << END
                    << std::endl;
    }
    else
    {
        std::cout << WHITE << "The ScavTrap unit " << YELLOW << BOLD
                    << this->name << END << WHITE << " is out of power, and cannot high five. This is so sad :(." << END
                    << std::endl;
    }
}