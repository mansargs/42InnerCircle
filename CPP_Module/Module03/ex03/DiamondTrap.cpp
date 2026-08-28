#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("Guest_clap_name"), FragTrap(),
							ScavTrap(), m_name("Guest") {
	m_hits = FragTrap::m_hits;
	m_energy = ScavTrap::m_energy;
	m_attack = FragTrap::m_attack;
	std::cout << "DiamondTrap default ctor called\n";
}

DiamondTrap::DiamondTrap(const std::string& n, unsigned hits, unsigned energy, unsigned attack)
				: ClapTrap(n + "_clap_name", hits, energy, attack), FragTrap(),
					ScavTrap(), m_name(n) {
	m_hits = FragTrap::m_hits;
	m_energy = ScavTrap::m_energy;
	m_attack = FragTrap::m_attack;
	std::cout << "DiamondTrap parametrized ctor called\n";
}


DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other),
													ScavTrap(other), m_name(other.m_name) {
	std::cout << "DiamondTrap copy ctor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		m_name = other.m_name;
	}
	std::cout << "DiamondTrap copy assignment called\n";
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap dtor called\n";
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << m_name
			  << " and ClapTrap name is " << ClapTrap::m_name
			  << std::endl;
}
