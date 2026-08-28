#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("ShrubberyCreationForm", sign, exec),
		  m_target("Undefined") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
		: AForm("ShrubberyCreationForm", sign, exec),
		  m_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
			: AForm(other),
			  m_target(other.m_target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	checkExecution(executor);
	std::ofstream outfile(std::string(m_target + "_shrubbery").c_str());
	if (!outfile.is_open())
		throw std::runtime_error("Failed to open file");
	outfile <<
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\ \n";
}
