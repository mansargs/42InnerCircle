#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal("Dog") {
	attribute = new (std::nothrow) Brain();
	std::cout << "Dog default ctor called\n";
}

Dog::Dog(const Dog& other) : AAnimal(other) {
	attribute = new (std::nothrow) Brain(*other.attribute);
	std::cout << "Dog copy ctor called\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete attribute;
		attribute = new (std::nothrow) Brain(*other.attribute);
	}
	std::cout << "Dog copy assignment called\n";
	return *this;
}

Dog::~Dog() {
	delete attribute;
	std::cout << "Dog dtor called\n";
}

void Dog::makeSound() const {
	std::cout << "Bark\n";
}

const Brain* Dog::getBrain() const {
	return attribute;
}
