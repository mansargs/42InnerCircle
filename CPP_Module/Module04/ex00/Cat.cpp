#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default ctor called\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy ctor called\n";
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		Animal::operator=(other);
	std::cout << "Cat copy assignment called\n";
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat dtor called\n";
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}
