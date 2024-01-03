# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main(void)
{
    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << "a is a : " << a->getType() << std::endl;
    a->makeSound();
    std::cout << "d is a : " << d->getType() << std::endl;
    d->makeSound();
    std::cout << "c is a : " << c->getType() << std::endl;
    c->makeSound();
    std::cout << "wa is a : " << wa->getType() << std::endl;
    wa->makeSound();
    std::cout << "wc is a : " << wc->getType() << std::endl;
    wc->makeSound();
    delete(a);
    delete(c);
    delete(d);
    delete(wa);
    delete(wc);
    return (0);
}