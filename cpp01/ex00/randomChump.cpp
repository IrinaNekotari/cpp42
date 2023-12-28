# include "Zombie.hpp"

/*
* Cette fonction crée un zombie sans new.
* le zombie n'était pas alloué, il n'aura pas être delete/free.
*/
void    randomChump(std::string name)
{
    Zombie z(name);
    z.announce();
}