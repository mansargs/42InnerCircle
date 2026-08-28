#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Bureaucrat Test ===\n\n";
	try {
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
		std::cout << "Increment grade..." << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		std::cout << "Decrement grade..." << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test high grade exception ===\n";
	try {
		Bureaucrat b("Bob", 0);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test low grade exception ===\n";
	try {
		Bureaucrat c("Charlie", 151);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test increment beyond limit ===\n";
	try {
		Bureaucrat d("Diana", 1);
		std::cout << d << std::endl;
		d.incrementGrade();
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test decrement beyond limit ===\n";
	try {
		Bureaucrat e("Edward", 150);
		std::cout << e << std::endl;
		e.decrementGrade();
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test copy constructor and assignment ===\n";
	try {
		Bureaucrat original("Fiona", 50);
		Bureaucrat copy = original;
		std::cout << "Copy: " << copy << std::endl;

		Bureaucrat assign("George", 100);
		assign = original;
		std::cout << "Assigned: " << assign << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
