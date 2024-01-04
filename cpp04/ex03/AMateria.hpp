# pragma once
# include <iostream>
# include "colors.h"
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;
    std::string color;
public:
    AMateria(std::string const & type);
    AMateria(const AMateria& am);
    AMateria& operator=(const AMateria& am);
    virtual ~AMateria();
    std::string const & getType(void) const;
    virtual AMateria* clone(void) const = 0;
    virtual void      use(ICharacter &target);
    virtual std::string getColor(void) const;
};