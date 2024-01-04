# include "Ultima.hpp"

Ultima::Ultima() : AMateria("Ultima")
{
    std::cout << "Ultima Materia constructor called." << std::endl;
    this->AMateria::color = PURPLE;
}

Ultima::~Ultima()
{
    std::cout << "Ultima Materia destructor called." << std::endl;
}

Ultima::Ultima(const Ultima& c) : AMateria("Ultima")
{
    (*this) = c;
}

Ultima& Ultima::operator=(const Ultima& c)
{
    std::cout << "Ultima Materia copy constructor called." << std::endl;
    this->AMateria::color = c.color;
    this->AMateria::type  = c.type;
    return (*this);
}

AMateria* Ultima::clone() const
{
    return ((Ultima*)this);
}

void Ultima::use(ICharacter &target)
{
    std::cout << WHITE << "* From the deepest pit of the seven hells to the very pinnacle of the heavens, the world shall tremble! Unleash Ultima! (target : " << RED << BOLD << target.getName()
            << END << WHITE << ") *" << END
            << std::endl;
}