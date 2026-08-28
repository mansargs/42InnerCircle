#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static bool	isFloatLiteral(const std::string& s);
		static bool	isDoubleLiteral(const std::string& s);
		static void	printPseudo(const std::string& s);
		static void printChar(double d);
		static void printInt(double d);
		static void printFloat(double d);
		static void printDouble(double d);
	public:
		static void convert(const std::string& literal);
};

#endif
