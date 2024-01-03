# pragma once
# include <iostream>
# include "colors.h"
# include "ICharacter.hpp"

class AMateria
{
private:
    /* data */
public:
    AMateria(std::string const & type);
    AMateria(const AMateria& am);
    AMateria& operator=(const AMateria& am);
    ~AMateria();
    std::string const & getType(void) const;
    virtual AMateria* clone(void) const = 0;
    virtual void      use(ICharacter &target);
};