# include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
    std::cout << "Cure Materia constructor called." << std::endl;
    this->AMateria::color = GREEN;
}

Cure::~Cure()
{
    std::cout << "Cure Materia destructor called." << std::endl;
}

Cure::Cure(const Cure& c) : AMateria("Cure")
{
    (*this) = c;
}

Cure& Cure::operator=(const Cure& c)
{
    std::cout << "Cure Materia copy constructor called." << std::endl;
    this->AMateria::color = c.color;
    this->AMateria::type  = c.type;
    return (*this);
}

AMateria* Cure::clone() const
{
    return ((Cure*)this);
}

void Cure::use(ICharacter &target)
{
    std::cout << WHITE << "* heals " << GREEN << BOLD << target.getName()
            << END << WHITE << " wounds *" << END
            << std::endl;
}