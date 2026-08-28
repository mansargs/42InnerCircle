#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Proper Animals ===\n";
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "\n=== Wrong Animals ===\n";
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongI = new WrongCat();
	std::cout << wrongI->getType() << std::endl;
	wrongI->makeSound();
	wrongMeta->makeSound();
	std::cout << "\n=== Clean Up ===\n";
	delete meta;
	delete j;
	delete i;
	delete wrongMeta;
	delete wrongI;
	return 0;
}
