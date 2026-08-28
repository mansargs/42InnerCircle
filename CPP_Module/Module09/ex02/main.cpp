#include "PmergeMe.hpp"
#include <iostream>
int main (int ac, char *av[]) {
	PmergeMe obj;

	if (!obj.argvValidation(ac, av)) {
		std::cerr << "Arguments are invalid" << std::endl;
		return 1;
	}
	obj.parsArgv(ac, av);
	obj.run();
}
