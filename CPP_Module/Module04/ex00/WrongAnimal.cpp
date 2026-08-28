#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Undefined") {
	std::cout << "WrongAnimal default ctor called\n";
}

WrongAnimal::WrongAnimal(const std::string &t) : type(t) {
	std::cout << "WrongAnimal parametrized ctor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "WrongAnimal copy ctor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		type = other.type;
	std::cout << "WrongAnimal copy assignment called\n";
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal dtor called\n";
}

const std::string& WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound is undefined\n";
}
