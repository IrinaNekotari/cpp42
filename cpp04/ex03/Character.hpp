# include "ICharacter.hpp"

class Character : public ICharacter
{
    protected:
        std::string name;
        AMateria* inventory[4];
    public:
        Character(std::string name);
        Character(const Character& c);
        ~Character();
        Character& operator=(const Character& c);
        std::string const & getName(void) const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void printInventory(void) const;
};