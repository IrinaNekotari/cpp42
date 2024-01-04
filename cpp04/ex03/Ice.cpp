# include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
    std::cout << "Ice Materia constructor called." << std::endl;
    this->color = CYAN;
}

Ice::~Ice()
{
    std::cout << "Ice Materia destructor called." << std::endl;
}

Ice::Ice(const Ice& c) : AMateria("Ice")
{
    (*this) = c;
}

Ice& Ice::operator=(const Ice& c)
{
    std::cout << "Ice Materia copy constructor called." << std::endl;
    this->color = c.color;
    this->type  = c.type;
    return (*this);
}

AMateria* Ice::clone() const
{
    return ((Ice*)this);
}

void Ice::use(ICharacter &target)
{
    std::cout << WHITE << "* shoots a ice bolt at " << RED << BOLD << target.getName()
            << END << WHITE << " *" << END
            << std::endl;
}