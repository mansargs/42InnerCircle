#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Guest", 100, 50, 20) {
	std::cout << "ScavTrap default ctor called\n";
}

ScavTrap::ScavTrap(const std::string& n, unsigned hits, unsigned energy,unsigned attack)
			: ClapTrap(n, hits, energy, attack) {
	std::cout << "ScavTrap parametrized ctor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy ctor called\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment called\n";
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap dtor called\n";
}

void ScavTrap::attack(const std::string &target) {
	if (!canAct()) {
		std::cout << "ScavTrap " << m_name
				  << " can't attack (no hits or energy)!\n";
		return;
	}
	--m_energy;
	std::cout << "ScavTrap " << m_name << " attacks " << target
			  << ", causing " << m_attack << " points of damage!\n";
}

void ScavTrap::guardGate() {
	if (!isAlive())
		std::cout << "ScavTrap" << m_name << "is died\n";
	else
		std::cout << "ScavTrap " << m_name << " is now in Gate keeper mode!\n";
}


