#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	std::cout << "=== INTERN FORM FACTORY TEST ===\n\n";
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 140);

	AForm* f1 = NULL;
	AForm* f2 = NULL;
	AForm* f3 = NULL;
	AForm* f4 = NULL;

	try
	{
		f1 = someRandomIntern.makeForm("shrubbery creation", "home");
		f2 = someRandomIntern.makeForm("robotomy request", "Bender");
		f3 = someRandomIntern.makeForm("presidential pardon", "Ford");
		f4 = someRandomIntern.makeForm("coffee request", "Office");

		std::cout << "\n--- Signing forms ---\n";
		if (f1) worker.signForm(*f1);
		if (f2) boss.signForm(*f2);
		if (f3) boss.signForm(*f3);

		std::cout << "\n--- Executing forms ---\n";
		if (f1) boss.executeForm(*f1);
		if (f2) boss.executeForm(*f2);
		if (f3) boss.executeForm(*f3);
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	delete f1;
	delete f2;
	delete f3;
	delete f4;
	std::cout << "\n=== END OF TEST ===\n";
	return 0;
}
