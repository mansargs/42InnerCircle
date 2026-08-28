#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <iostream>

RPN::RPN() {}

RPN::RPN(const RPN& other) : s(other.s) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		s = other.s;
	return *this;
}

RPN::~RPN() {}

bool RPN::tokenValidation(const std::string& token) {
	if (token.length() != 1)
		return false;
	char c = token[0];
	if (!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
		return false;
	return true;
}

void RPN::evaluate(const std::string& line) {
	std::stringstream ss(line);
	std::string token;

	while (ss >> token) {
		if (!tokenValidation(token)) {
			std::cerr << "Error\n";
			return;
		}
		char c = token[0];
		if (std::isdigit(c)) {
			s.push(c - '0');
		} else {
			if (s.size() < 2) {
				std::cerr << "Error\n";
				return;
			}
			int b = s.top(); s.pop();
			int a = s.top(); s.pop();
			int res = 0;
			switch (c) {
				case '+': res = a + b; break;
				case '-': res = a - b; break;
				case '*': res = a * b; break;
				case '/':
					if (b == 0) {
						std::cerr << "Error: division by zero\n";
						return;
					}
					res = a / b;
					break;
			}
			s.push(res);
		}
	}
	if (s.size() != 1) {
		std::cerr << "Error\n";
		return;
	}
	std::cout << s.top() << std::endl;
}
