# include "Character.hpp"

/*        Character();
        Character(const Character& c);
        ~Character();
        Character& operator=(const Character& c);
        std::string const & getName(void) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);*/

Character::Character(std::string name)
{
    this->name = name;
    for (size_t i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
    std::cout << BLUE << BOLD << name << END << WHITE " joins the fight !" << END << std::endl;
}

Character::Character(const Character& c)
{
    (*this) = c;
}

Character& Character::operator=(const Character& c)
{
    std::cout << BLUE << BOLD << this->name << END << WHITE << " has been cloned." << std::endl;
    this->name = c.name;
    for (size_t i = 0; i < 4; i++)
    {
        this->inventory[i] = c.inventory[i];
    }
    
    return (*this);
}

Character::~Character()
{
    std::cout << BLUE << BOLD << this->name << END << WHITE << " has been put out of action (RIP)." << END << std::endl;
}

std::string const & Character::getName(void) const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (NULL == m)
    {
        std::cout << BLUE << BOLD << this->name << END << WHITE << " can't equip a materia if it doesn't exist ! "
                    << std::endl;
        return ;
    }
    for (size_t i = 0; i < 4; i++)
    {
        if (NULL == this->inventory[i])
        {
            this->inventory[i] = m;
            std::cout << BLUE << BOLD << this->name << END << WHITE << " is now equipped with " 
                        << this->inventory[i]->getColor() << BOLD << this->inventory[i]->getType()
                        << END << WHITE " in slot " << i << "."
                        << std::endl;
            return ;
        }
    }
    std::cout << BLUE << BOLD << this->name << END << WHITE << " can't equip more materias ! "
                << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        if (NULL != this->inventory[idx])
        {
            delete (this->inventory[idx]);
            this->inventory[idx] = NULL;
            std::cout << BLUE << BOLD << this->name << END << WHITE << " unequipped the materia in slot "
                        << idx << "." << std::endl; 
        }
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4)
    {
        if (NULL != this->inventory[idx])
        {    
            std::cout << BLUE << BOLD << this->name << END << WHITE << " : ";
            this->inventory[idx]->use(target);
        }
    }
}

void Character::printInventory(void) const
{
    std::cout << WHITE << "### Inventory of "<< BLUE << BOLD <<this->name << END << WHITE << " ###"<< END << std::endl;
    for (size_t i = 0; i < 4; i++)
    {
        std::cout << WHITE << "Slot " << i << " : ";
        if (NULL == this->inventory[i])
            std::cout << "Empty" << std::endl;
        else
            std::cout << this->inventory[i]->getColor() << BOLD << this->inventory[i]->getType() << END << std::endl;
    }
}