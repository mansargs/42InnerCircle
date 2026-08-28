#include "Fixed.hpp"
#include <cmath>

const int Fixed::fraction_bits = 8;

Fixed::Fixed() : raw(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	raw = num << fraction_bits;
};

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	raw = static_cast<int>(roundf(num * (1 << fraction_bits)));
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

int	Fixed::toInt(void) const {
	return raw >> fraction_bits;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(raw) / (1 << fraction_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed& f) {
	out << f.toFloat();
	return out;
}
