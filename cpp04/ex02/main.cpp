# include "Cat.hpp"
# include "Dog.hpp"

int main(void)
{
    const AAnimal* d = new Dog();
    const AAnimal* c = new Cat();
    delete(c);
    delete(d);
    Dog test;
    Dog tmp = test;
    const AAnimal* animals[4] = {new Dog(), new Cat(), new Dog(), new Cat()};
    for (size_t i = 0; i < 4; i++)
    {
        animals[i]->makeSound();
        delete(animals[i]);
    }
    return (0);
}