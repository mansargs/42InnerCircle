#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Bureaucrats & Forms Test ===\n\n";
	try
	{
		Bureaucrat alice("Alice", 140);
		Bureaucrat bob("Bob", 50);
		Bureaucrat charlie("Charlie", 1);

		std::cout << alice << bob << charlie << "\n";

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Marvin");
		PresidentialPardonForm pardon("Ford");

		std::cout << "\n--- Initial forms ---\n";
		std::cout << shrub << "\n" << robot << "\n" << pardon << "\n";

		std::cout << "\n--- Signing Forms ---\n";
		alice.signForm(shrub);
		bob.signForm(robot);
		charlie.signForm(pardon);

		std::cout << "\n--- Executing Forms ---\n";
		std::cout << "\n[Expect file: home_shrubbery]\n";
		bob.executeForm(shrub);
		bob.executeForm(robot);
		charlie.executeForm(pardon);

		std::cout << "\n[Try executing unsigned form]\n";
		ShrubberyCreationForm shrub2("office");
		bob.executeForm(shrub2);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << "\n";
	}
	std::cout << "\n=== End of Test ===\n";
	return 0;
}
