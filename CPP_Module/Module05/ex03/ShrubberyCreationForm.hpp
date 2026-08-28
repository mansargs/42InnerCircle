#ifndef SHRUBBERY_CREATIONAL_FORM_HPP
# define SHRUBBERY_CREATIONAL_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		static const int sign = 145;
		static const int exec = 137;

		std::string m_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		virtual void execute(Bureaucrat const & executor) const;
};

#endif
