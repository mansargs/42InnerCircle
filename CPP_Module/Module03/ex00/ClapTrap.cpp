#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap() : m_name("Guest"), m_hits(10), m_energy(10), m_attack(0) {
	std::cout << "ClapTrap default ctor called\n";
}

ClapTrap::ClapTrap(const std::string &n, unsigned hits, unsigned energy, unsigned attack)
			: m_name(n), m_hits(hits),
			  m_energy(energy), m_attack(attack) {
	std::cout << "ClapTrap parameterized ctor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) : m_name(other.m_name), m_hits(other.m_hits),
											m_energy(other.m_energy), m_attack(other.m_attack)
											 {
	std::cout << "ClapTrap copy ctor called\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		m_name = other.m_name;
		m_attack = other.m_attack;
		m_hits = other.m_hits;
		m_energy = other.m_energy;
	}
	std::cout << "ClapTrap copy assignment called\n";
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap dtor called\n";
}

bool ClapTrap::canAct() const {
	return m_hits > 0 && m_energy > 0;
}

bool ClapTrap::isFatalDamage(unsigned int amount) const {
	return amount >= m_hits;
}

void ClapTrap::attack(const std::string &target) {
	if (!canAct()) {
		std::cout << "ClapTrap " << m_name
				<< " can't attack because it has no hit points or energy points!\n";
		return;
	}
	--m_energy;
	std::cout << "ClapTrap " << m_name << " attacks " << target << ", causing "
				<< m_attack << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canAct()) {
		std::cout << "ClapTrap " << m_name
				<< " can't repair because it has no hit points or energy points!\n";
		return;
	}
	--m_energy;
	if (std::numeric_limits<unsigned>::max() - amount <= m_hits) {
		std::cout << "ClapTrap " << m_name << " has full hit points!\n";
		m_hits = std::numeric_limits<unsigned>::max();
	} else {
		m_hits += amount;
		std::cout << "ClapTrap " << m_name << " repairs itself, restoring "
				<< amount << " hit points!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (isFatalDamage(amount)) {
		m_hits = 0;
		std::cout << "ClapTrap " << m_name << " has died\n";
		return ;
	}
	m_hits -= amount;
	std::cout << "ClapTrap " << m_name << " takes " << amount << " points of damage!\n";
}

