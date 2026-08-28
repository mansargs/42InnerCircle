#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Bureaucrat alice("Alice", 50);
	Bureaucrat bob("Bob", 5);
	Form taxForm("TaxForm", 30, 10);
	Form permitForm("PermitForm", 5, 1);
	std::cout << taxForm << std::endl;
	std::cout << permitForm << std::endl;
	alice.signForm(taxForm);
	bob.signForm(taxForm);
	bob.signForm(permitForm);
	std::cout << taxForm << std::endl;
	std::cout << permitForm << std::endl;
	return 0;
}
