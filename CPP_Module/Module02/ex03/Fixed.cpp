#include "Fixed.hpp"
#include <cmath>
#include <stdexcept>

const int Fixed::fraction_bits = 8;

Fixed::Fixed() : raw(0) {}

Fixed::Fixed(const int num) { raw = num << fraction_bits; }

Fixed::Fixed(const float num) {
	raw = static_cast<int>(roundf(num * (1 << fraction_bits)));
}

Fixed::Fixed(const Fixed& other) : raw(other.raw) {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		raw = other.raw;
	return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return raw;
}

void Fixed::setRawBIts(int const raw) {
	this->raw = raw;
}

int	Fixed::toInt(void) const { return raw >> fraction_bits; }

float	Fixed::toFloat(void) const {
	return static_cast<float>(raw) / (1 << fraction_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed& f) {
	out << f.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& other) const  { return raw > other.raw; }
bool Fixed::operator<(const Fixed& other) const  { return raw < other.raw; }
bool Fixed::operator>=(const Fixed& other) const { return raw >= other.raw; }
bool Fixed::operator<=(const Fixed& other) const { return raw <= other.raw; }
bool Fixed::operator==(const Fixed& other) const { return raw == other.raw; }
bool Fixed::operator!=(const Fixed& other) const { return raw != other.raw; }

Fixed Fixed::operator+(const Fixed& other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other.raw == 0)
		throw std::runtime_error("Division by 0");
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	raw += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	raw -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	raw += 1;
	return temp;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	raw -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2) {
	return (num1 < num2)? num1 : num2;
}


Fixed& Fixed::max(Fixed& num1, Fixed& num2) {
	return (num1 > num2)? num1 : num2;
}


const Fixed& Fixed::min(const Fixed& num1, const Fixed& num2) {
	return (num1 < num2)? num1 : num2;
}


const Fixed& Fixed::max(const Fixed& num1,const Fixed& num2) {
	return (num1 > num2)? num1 : num2;
}
