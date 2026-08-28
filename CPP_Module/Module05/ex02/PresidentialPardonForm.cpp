#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("PresidentialPardonForm", sign, exec),
		  m_target("Undefined") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: AForm("PresidentialPardonForm", sign, exec),
		  m_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
			: AForm(other),
			  m_target(other.m_target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	checkExecution(executor);
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox.\n";
}
