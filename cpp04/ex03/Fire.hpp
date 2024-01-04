# include "AMateria.hpp"

class Fire : public AMateria
{
    public:
        Fire();
        ~Fire();
        Fire(const Fire& c);
        Fire& operator=(const Fire& c);
        void use(ICharacter &target);
        AMateria* clone(void) const;
};