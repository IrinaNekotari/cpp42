# pragma once
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *inventory[4];
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource& m);
    MateriaSource& operator=(const MateriaSource& m);
    AMateria*       getMateria(std::string const & type);
    AMateria*       createMateria(std::string const & type);
    void            learnMateria(AMateria*);
};