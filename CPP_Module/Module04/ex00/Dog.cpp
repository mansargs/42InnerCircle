#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cout << "Dog default ctor called\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy ctor called\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Dog copy assignment called\n";
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog dtor called\n";
}

void Dog::makeSound() const {
	std::cout << "Bark\n";
}
