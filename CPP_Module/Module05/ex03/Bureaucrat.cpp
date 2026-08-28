#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

void Bureaucrat::validateGrade(int grade) const {
	if (grade < highest_grade)
		throw GradeTooHighException();
	if (grade > lowest_grade)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : m_name("Undefined"), m_grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : m_name(name) {
	validateGrade(grade);
	m_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : m_name(other.m_name) , m_grade(other.m_grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		m_grade = other.m_grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return m_name;
}

int Bureaucrat::getGrade() const {
	return m_grade;
}

void Bureaucrat::incrementGrade() {
	validateGrade(m_grade - 1);
	--m_grade;
}

void Bureaucrat::decrementGrade() {
	validateGrade(m_grade + 1);
	++m_grade;
}

void Bureaucrat::signForm(AForm& f) const {
	try {
		f.beSigned(*this);
		std::cout << m_name << " signed " << f.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << m_name << " couldn’t sign " << f.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << m_name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << m_name << " couldn’t execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return os;
}
