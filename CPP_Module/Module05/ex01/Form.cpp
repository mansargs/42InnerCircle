#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade is too low";
}

void Form::validateGrade(int grade) const {
	if (grade < highest_grade)
		throw GradeTooHighException();
	if (grade > lowest_grade)
		throw GradeTooLowException();
}

Form::Form(): m_name("Unnamed"), m_isSigned(false), m_gradeToSign(150), m_gradeToExecute(150) {
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : m_name(name), m_isSigned(false),
					m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute) {
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

Form::Form(const Form& other) : m_name(other.m_name), m_isSigned(other.m_isSigned),
								m_gradeToSign(other.m_gradeToSign), m_gradeToExecute(other.m_gradeToExecute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		m_isSigned = other.m_isSigned;
	return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
	return m_name;
}

bool Form::isSigned() const {
	return m_isSigned;
}

int Form::getGradeToSign() const {
	return m_gradeToSign;
}

int Form::getGradeToExecute() const {
	return m_gradeToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > m_gradeToSign)
		throw GradeTooLowException();
	m_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form \"" << f.getName() << "\", signed: "
	   << (f.isSigned() ? "yes" : "no")
	   << ", grade required to sign: " << f.getGradeToSign()
	   << ", grade required to execute: " << f.getGradeToExecute();
	return os;
}
