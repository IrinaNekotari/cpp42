# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        ~Ice();
        Ice(const Ice& c);
        Ice& operator=(const Ice& c);
        virtual void use(ICharacter &target);
        virtual AMateria* clone(void) const;
};