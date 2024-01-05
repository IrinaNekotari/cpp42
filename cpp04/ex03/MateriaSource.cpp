# include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        this->inventory[i] = NULL;
    }
    std::cout << "Constructor for MateriaSource called." << std::endl ;
}

MateriaSource::~MateriaSource()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (NULL != this->inventory[i])
            delete (this->inventory[i]);
    }
    std::cout << "Destructor for MateriaSource called." << std::endl ;
}

MateriaSource::MateriaSource(const MateriaSource& m)
{
    (*this) = m;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& m)
{
    for (size_t i = 0; i < 4; i++)
    {
        this->inventory[i] = m.inventory[i];
    }
    std::cout << "Copy constructor for MateriaSource called." << std::endl ;
    return (*this);
}

AMateria*       MateriaSource::getMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (NULL != this->inventory[i] && this->inventory[i]->getType() == type)
            return (this->inventory[i]);
    }
    return (NULL);
}

AMateria*       MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (NULL != this->inventory[i] && this->inventory[i]->getType() == type)
            return (this->inventory[i]->clone());
    }
    return (NULL);
}

void            MateriaSource::learnMateria(AMateria* m)
{
    for (size_t i = 0; i < 4; i++)
    {
        if (NULL == this->inventory[i])
        {
            this->inventory[i] = m;
            std::cout << "Successfully learned materia " << m->getType() << "." << std::endl ;
            return ;
        }
    }
    std::cout << "Cannot learn a new materia type : knowledge full." << std::endl ;
}