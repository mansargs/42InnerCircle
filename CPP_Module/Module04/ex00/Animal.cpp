#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Undefined") {
	std::cout << "Animal default ctor called\n";
}

Animal::Animal(const std::string &t) : type(t) {
	std::cout << "Animal parametrized ctor called\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy ctor called\n";
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		type = other.type;
	std::cout << "Animal copy assignment called\n";
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal dtor called\n";
}

const std::string& Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal sound is undefined\n";
}
