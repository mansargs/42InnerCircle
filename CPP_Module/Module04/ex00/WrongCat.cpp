#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("Cat") {
	std::cout << "WrongCat default ctor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy ctor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << "WrongCat copy assignment called\n";
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat dtor called\n";
}

void WrongCat::makeSound() const {
	std::cout << "Meow\n";
}
