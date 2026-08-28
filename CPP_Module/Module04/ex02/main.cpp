#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;
	delete i;
	return 0;
}

// int main()
// {
// 	const int SIZE = 6;
// 	AAnimal* animals[SIZE];
// 	std::cout << "=== Creating Animals ===\n";
// 	for (int i = 0; i < SIZE; ++i) {
// 		if (i < SIZE / 2)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 	}
// 	std::cout << "\n=== Making Sounds ===\n";
// 	for (int i = 0; i < SIZE; ++i)
// 		animals[i]->makeSound();
// 	std::cout << "\n=== Testing Deep Copy for Dog (Brain addresses) ===\n";
// 	Dog* dog1 = new Dog();
// 	Dog* dog2 = new Dog(*dog1);
// 	std::cout << "dog1 Brain address: " << dog1->getBrain() << std::endl;
// 	std::cout << "dog2 Brain address: " << dog2->getBrain() << std::endl;
// 	if (dog1->getBrain() != dog2->getBrain())
// 		std::cout << "✅ Dog deep copy confirmed\n";
// 	else
// 		std::cout << "❌ Dog shallow copy detected\n";
// 	delete dog1;
// 	delete dog2;
// 	std::cout << "\n=== Testing Deep Copy for Cat (Brain addresses) ===\n";
// 	Cat* cat1 = new Cat();
// 	Cat* cat2 = new Cat();
// 	*cat2 = *cat1;
// 	std::cout << "cat1 Brain address: " << cat1->getBrain() << std::endl;
// 	std::cout << "cat2 Brain address: " << cat2->getBrain() << std::endl;
// 	if (cat1->getBrain() != cat2->getBrain())
// 		std::cout << "✅ Cat deep copy confirmed\n";
// 	else
// 		std::cout << "❌ Cat shallow copy detected\n";
// 	delete cat1;
// 	delete cat2;
// 	std::cout << "\n=== Cleaning Up Animals Array ===\n";
// 	for (int i = 0; i < SIZE; ++i)
// 		delete animals[i];
// 	std::cout << "\n=== Done ===\n";
// 	return 0;
// }
