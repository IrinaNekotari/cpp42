# include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    std::cout << "Constructor for Materia called." << std::endl;
    this->type = type;
    this->color = WHITE;
}

AMateria& AMateria::operator=(const AMateria& am)
{
    std::cout << "Copy constructor for Materia called." << std::endl;
    this->type = am.type;
    this->color = am.color;
    return (*this);
}

AMateria::AMateria(const AMateria& am)
{
    (*this) = am;
}

AMateria::~AMateria()
{
    std::cout << "Destructor for Materia called." << std::endl;
}

 std::string const & AMateria::getType(void) const
 {
    return (this->type);
 }

 AMateria* AMateria::clone(void) const
 {
    return ((AMateria*)this);
 }

void    AMateria::use(ICharacter& target)
{
    std::cout << "Materia " << this->type << " used on " << target.getName() << std::endl;
}

std::string AMateria::getColor(void) const
{
    return (this->color);
}