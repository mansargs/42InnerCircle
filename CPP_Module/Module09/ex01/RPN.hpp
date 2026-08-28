#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN {
	private:
		std::stack<int> s;

		bool tokenValidation(const std::string& token);
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void evaluate(const std::string& line);
};

#endif
