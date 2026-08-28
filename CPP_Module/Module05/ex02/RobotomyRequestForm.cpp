#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("RobotomyRequestForm", sign, exec),
		  m_target("Undefined") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
		: AForm("RobotomyRequestForm", sign, exec),
		  m_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
			: AForm(other),
			  m_target(other.m_target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	checkExecution(executor);
	std::srand(std::time(0));
	std::cout << "* drilling noises *\n";
	if (std::rand() % 2 == 0)
		std::cout << m_target << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed on " << m_target << "!\n";
}
