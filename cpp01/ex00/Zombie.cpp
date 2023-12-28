# include "Zombie.hpp"

/*
* Constructeur : Cette fonction est appelée lorsqu'un zombie est crée par new.
*/
Zombie::Zombie(std::string name)
{
    this->name = name;
}

/*
* Destructeur : Cette fonction est appelée lorsqu'un zombie est détruit par delete.
*/
Zombie::~Zombie()
{
    std::cout << WHITE << "Subject " << RED << WHITE
                << this->name << " is destroyed and forever gone." << END
                << std::endl;
}

void    Zombie::announce( void )
{
    std::cout << RED << BOLD << this->name 
                << END << WHITE << ": BraiiiiiiinnnzzzZ..." 
                << END << std::endl;
}