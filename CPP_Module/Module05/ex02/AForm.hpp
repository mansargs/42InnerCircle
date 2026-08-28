#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		static const int highest_grade = 1;
		static const int lowest_grade = 150;

		const std::string m_name;
		bool m_isSigned;
		const int m_gradeToSign;
		const int m_gradeToExecute;
	private:
		void validateGrade(int grade) const;
	protected:
		void checkExecution(const Bureaucrat& executor) const;
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
	public:
		const std::string& getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};
		class FormNotSignedException : public std::exception {
		public:
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
