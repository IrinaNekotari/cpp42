# include "AMateria.hpp"

class Ultima : public AMateria
{
    public:
        Ultima();
        ~Ultima();
        Ultima(const Ultima& c);
        Ultima& operator=(const Ultima& c);
        void use(ICharacter &target);
        AMateria* clone(void) const;
};