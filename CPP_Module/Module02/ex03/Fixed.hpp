#pragma once

#include <iostream>

class Fixed {
	private:
		static const int fraction_bits;
		int raw;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBIts(int const row);

		float toFloat( void ) const;
		int toInt( void ) const;

		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed& min(Fixed& num1, Fixed& num2);
		static Fixed& max(Fixed& num1, Fixed& num2);
		static const Fixed& min(const Fixed& num1, const Fixed& num2);
		static const Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream &operator<<(std::ostream &out, const Fixed& obj);
