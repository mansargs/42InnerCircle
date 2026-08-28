#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat") {
	attribute = new (std::nothrow) Brain();
	std::cout << "Cat default ctor called\n";
}

Cat::Cat(const Cat& other) : AAnimal(other) {
	attribute = new (std::nothrow) Brain(*other.attribute);
	std::cout << "Cat copy ctor called\n";
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete attribute;
		attribute = new (std::nothrow) Brain(*other.attribute);
	}
	std::cout << "Cat copy assignment called\n";
	return *this;
}

Cat::~Cat() {
	delete attribute;
	std::cout << "Cat dtor called\n";
}

void Cat::makeSound() const {
	std::cout << "Meow\n";
}

const Brain* Cat::getBrain() const {
	return attribute;
}
