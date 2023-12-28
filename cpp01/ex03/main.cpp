#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    Weapon hamon = Weapon("sun rays power");
    HumanA jojo("Johnattan", hamon);
    jojo.attack();
    hamon.setType("stone mask");
    jojo.attack();
    HumanB dio("DIO");
    dio.setWeapon(hamon);
    dio.attack();
    hamon.setType("the WORLD");
    dio.attack();

    return (0);
}