# include "Character.hpp"
# include "Ice.hpp"
# include "Fire.hpp"
# include "Ultima.hpp"
# include "Cure.hpp"
# include "MateriaSource.hpp"

int main (void)
{
    IMateriaSource* source = new MateriaSource();
    
    ICharacter* cloud     = new Character("Cloud");
    ICharacter* barret    = new Character("Barret");
    ICharacter* aerith    = new Character("Aerith");
    ICharacter* sephiroth = new Character("SEPHIROTH");
    AMateria* tmp;

    source->learnMateria(new Ice());
    source->learnMateria(new Fire());
    source->learnMateria(new Cure());
    source->learnMateria(new Ultima());

    cloud->printInventory();
    barret->printInventory();
    aerith->printInventory();
    tmp = source->createMateria("Ice");
    cloud->equip(tmp);
    cloud->equip(tmp);
    tmp = source->createMateria("Cure");
    aerith->equip(tmp);
    aerith->equip(tmp);
    aerith->equip(tmp);
    aerith->equip(tmp);
    tmp = source->createMateria("Thunder");
    cloud->equip(tmp);
    tmp = source->createMateria("Ultima");
    cloud->equip(tmp);
    tmp = source->createMateria("Fire");
    cloud->equip(tmp);
    cloud->equip(tmp);
    cloud->printInventory();
    barret->printInventory();
    aerith->printInventory();
    cloud->use(0, *sephiroth);
    cloud->use(2, *sephiroth);
    cloud->use(3, *sephiroth);
    aerith->use(1, *cloud);

    delete (cloud);
    delete (barret);
    delete (aerith);
    delete (sephiroth);
    delete (source);
}