# include <ctime>
# include <cstdlib>
# include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base * generate(void) {
	int mod = std::rand() % 3;
	switch (mod) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

static void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

static void identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	} catch (...) {}
	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	} catch(...) {}
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	} catch(...) {}
}

int main() {
	std::srand(std::time(0));
	for (int i = 0; i < 10; i++) {
		Base* obj = generate();
		std::cout << "Identify by pointer: ";
		identify(obj);
		std::cout << "Identify by reference: ";
		identify(*obj);
		delete obj;
		std::cout << std::endl;
	}
	return 0;
}
