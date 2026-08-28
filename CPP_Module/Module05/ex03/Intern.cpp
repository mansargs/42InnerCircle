#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	static_cast<void>(other);
}

Intern& Intern::operator=(const Intern& other) {
	static_cast<void>(other);
	return *this;
}

Intern::~Intern() {}

AForm*  Intern::createShrubbery(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

AForm*  Intern::createRobotomy(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

AForm*  Intern::createPresidential(const std::string& target) const {
	return new PresidentialPardonForm(target);
}


AForm* Intern::makeForm(const std::string& form, const std::string& target) const {
	const std::string types[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (Intern::*creators[3])(const std::string&) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	for (int i = 0; i < 3; ++i) {
		if (types[i] == form) {
			std::cout << "Intern creates " << form << std::endl;
			return (this->*creators[i])(target);
		}
	}
	std::cerr << "Intern cannot create form: " << form << std::endl;
	return NULL;
}

