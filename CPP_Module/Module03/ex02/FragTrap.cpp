#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Guest", 100, 100, 30) {
	std::cout << "FragTrap default ctor called\n";
}

FragTrap::FragTrap(const std::string& n, unsigned hits, unsigned energy,unsigned attack)
			: ClapTrap(n, hits, energy, attack) {
	std::cout << "FragTrap parametrized ctor called\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy ctor called\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment called\n";
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap dtor called\n";
}

void FragTrap::highFivesGuys(void) {
	std::cout << "High five, guys!\n";
}

