#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	attribute = new (std::nothrow) Brain();
	std::cout << "Dog default ctor called\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	attribute = new (std::nothrow) Brain(*other.attribute);
	std::cout << "Dog copy ctor called\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
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
