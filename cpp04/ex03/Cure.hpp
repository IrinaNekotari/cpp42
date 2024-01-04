# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure& c);
        Cure& operator=(const Cure& c);
        void use(ICharacter &target);
        AMateria* clone(void) const;
};