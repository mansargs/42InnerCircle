#include "Fixed.hpp"
#include <iostream>

const int Fixed::fraction_bits = 8;

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) : raw(other.raw) {
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		raw = other.raw;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return raw;
}

void Fixed::setRawBIts(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->raw = raw;
}
