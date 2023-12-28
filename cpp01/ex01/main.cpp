# include "Zombie.hpp"

int main(void)
{
    Zombie *horde = zombieHorde(10, "Zooombs");
    int i;

    i = 0;
    while (i < 10)
    {
        horde[i].announce();
        i++;
    }
    delete [] horde;
    return (0);
}