#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : type("Undefined") {
	std::cout << "AAnimal default ctor called\n";
}

AAnimal::AAnimal(const std::string &t) : type(t) {
	std::cout << "AAnimal parametrized ctor called\n";
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	std::cout << "AAnimal copy ctor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other)
		type = other.type;
	std::cout << "AAnimal copy assignment called\n";
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal dtor called\n";
}

const std::string& AAnimal::getType() const {
	return type;
}

