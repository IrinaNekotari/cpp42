# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->name = name;
    this->ClapTrap::name = name + "_clap_name";
    FragTrap::hp = 100;
    ScavTrap::ep = 50;
    FragTrap::ap = 30;
    std::cout << WHITE << "This is getting beyond ridiculous. The super duper DiamondTrap " << BLUE << BOLD
                << name << END << WHITE << " has arisen !!!!!" << END
                << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << WHITE << "The Ultimate Mega Super " << BLUE << BOLD
                << this->name << END << WHITE << " is gone. Finally." << END
                << std::endl;  
}

void    DiamondTrap::whoAmI(void)
{
    std::cout << WHITE << "The diamond trap " << BLUE << BOLD
                << this->name << END << WHITE << "(unit name "
                << CYAN << BOLD << this->ClapTrap::name << END << WHITE
                << ") is having an existential crisis and pondering is own existance and identity." << END
                << std::endl;  
}