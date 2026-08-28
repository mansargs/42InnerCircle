#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form isn't signed";
}

void AForm::validateGrade(int grade) const {
	if (grade < highest_grade)
		throw GradeTooHighException();
	if (grade > lowest_grade)
		throw GradeTooLowException();
}

AForm::AForm(): m_name("Unnamed"), m_isSigned(false), m_gradeToSign(150), m_gradeToExecute(150) {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : m_name(name), m_isSigned(false),
					m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute) {
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

AForm::AForm(const AForm& other) : m_name(other.m_name), m_isSigned(other.m_isSigned),
								m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		m_isSigned = other.m_isSigned;
	return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
	return m_name;
}

bool AForm::isSigned() const {
	return m_isSigned;
}

int AForm::getGradeToSign() const {
	return m_gradeToSign;
}

int AForm::getGradeToExecute() const {
	return m_gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > m_gradeToSign)
		throw GradeTooLowException();
	m_isSigned = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const {
	if (!m_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > m_gradeToExecute)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form \"" << f.getName() << "\", signed: "
	   << (f.isSigned() ? "yes" : "no")
	   << ", grade required to sign: " << f.getGradeToSign()
	   << ", grade required to execute: " << f.getGradeToExecute();
	return os;
}
