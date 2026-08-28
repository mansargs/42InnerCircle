#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { static_cast<void>(other); }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	static_cast<void>(other);
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isFloatLiteral(const std::string& s) {
	return s == "nanf" || s == "+inff" || s == "-inff";
}

bool ScalarConverter::isDoubleLiteral(const std::string& s) {
	return s == "nan" || s == "+inf" || s == "-inf";
}

void ScalarConverter::printPseudo(const std::string& s)
{
	double d = 0;
	if (isFloatLiteral(s))
		d = std::strtof(s.c_str(), NULL);
	else
		d = std::strtod(s.c_str(), NULL);
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << static_cast<float>(d) << "f\n";
	std::cout << "double: " << d << "\n";
}

void ScalarConverter::printChar(double d) {
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127 || d != static_cast<int>(d))
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << static_cast<char>(d) << "'\n";
}

void ScalarConverter::printInt(double d) {
	if (std::isnan(d) || std::isinf(d)
		|| d < std::numeric_limits<int>::min()
		|| d > std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(d) << "\n";
}

void ScalarConverter::printFloat(double d) {
	std::cout << "float: " << static_cast<float>(d);
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << "f\n";
}

void ScalarConverter::printDouble(double d) {
	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << "\n";
}

void ScalarConverter::convert(const std::string& literal) {
	double d = 0;
	char* end = NULL;

	if (isFloatLiteral(literal) || isDoubleLiteral(literal)) {
		printPseudo(literal);
		return;
	}
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
		d = static_cast<double>(literal[0]);
	}
	else if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'') {
		d = static_cast<double>(literal[1]);
	}
	else {
		std::string tmp = literal;
		if (tmp.size() > 1 && tmp[tmp.size() - 1] == 'f') {
			tmp = tmp.substr(0, tmp.size() - 1);
		}
		d = std::strtod(tmp.c_str(), &end);
		if (*end != '\0') {
			std::cout << "char: impossible\n"
					  << "int: impossible\n"
					  << "float: impossible\n"
					  << "double: impossible\n";
			return;
		}
	}
	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
