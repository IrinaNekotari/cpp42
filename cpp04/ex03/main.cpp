# include "Character.hpp"
# include "Ice.hpp"
# include "Fire.hpp"
# include "Ultima.hpp"
# include "Cure.hpp"

int main (void)
{
    ICharacter* cloud     = new Character("Cloud");
    ICharacter* barret    = new Character("Barret");
    ICharacter* aerith    = new Character("Aerith");
    ICharacter* sephiroth = new Character("SEPHIROTH");

    AMateria* ice = new Ice();

    cloud->printInventory();
    cloud->equip(ice);
    cloud->equip(ice);
    cloud->equip(ice);
    cloud->equip(ice);
    cloud->equip(ice);
    cloud->printInventory();
    cloud->use(0, *sephiroth);

    delete (cloud);
    delete (barret);
    delete (aerith);
    delete (sephiroth);
    delete (ice);
}