# include "Zombie.hpp"

/*
* Cette fonction crée un zombie avec new.
* new alloue la mémoire nécessaire pour notre ami nécromantique.
*/
Zombie *newZombie(std::string name)
{
    return (new Zombie(name));
}