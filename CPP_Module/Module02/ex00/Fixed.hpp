#pragma once

class Fixed {
	private:
		static const int fraction_bits;
		int raw;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBIts(int const raw);
};
