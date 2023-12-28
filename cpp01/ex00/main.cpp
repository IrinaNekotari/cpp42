# include "Zombie.hpp"

int main(void)
{
    std::string name;

    std::cout << "Création d'un zombie sans new (stack)." << std::endl;
    std::cout << "Nom : " << std::flush;
    std::cin >> name;
    Zombie z1(name);
    z1.announce();
    std::cout << "Création d'un zombie avec new (heap)." << std::endl;
    std::cout << "Nom : " << std::flush;
    std::cin >> name;
    Zombie *z2 = newZombie(name);
    z2->announce();
    delete z2;
    std::cout << "Création d'un zombie via randomChump()." << std::endl;
    randomChump("Zombieman");
    return (0);
}