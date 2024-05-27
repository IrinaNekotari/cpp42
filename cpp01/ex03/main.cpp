#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    Weapon hamon = Weapon("sun rays power");
    HumanA jojo("Johnathan", hamon);
    jojo.attack();
    hamon.setType("G U N");
    jojo.attack();
    hamon.setType("stone mask");
    HumanB dio("DIO");
    dio.attack();
    dio.setWeapon(hamon);
    dio.attack();
    hamon.setType("the WORLD");
    dio.attack();

    return (0);
}