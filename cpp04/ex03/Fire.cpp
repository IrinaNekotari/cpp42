# include "Fire.hpp"

Fire::Fire() : AMateria("Fire")
{
    std::cout << "Fire Materia constructor called." << std::endl;
    this->AMateria::color = RED;
}

Fire::~Fire()
{
    std::cout << "Fire Materia destructor called." << std::endl;
}

Fire::Fire(const Fire& c) : AMateria("Fire")
{
    (*this) = c;
}

Fire& Fire::operator=(const Fire& c)
{
    std::cout << "Fire Materia copy constructor called." << std::endl;
    this->AMateria::color = c.color;
    this->AMateria::type  = c.type;
    return (*this);
}

AMateria* Fire::clone() const
{
    return ((Fire*)this);
}

void Fire::use(ICharacter &target)
{
    std::cout << WHITE << "* shoots a firebolt at " << RED << BOLD << target.getName()
            << END << WHITE << " *" << END
            << std::endl;
}