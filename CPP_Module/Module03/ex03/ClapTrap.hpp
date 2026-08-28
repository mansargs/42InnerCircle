#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap {
	protected:
		std::string m_name;
		unsigned    m_hits;
		unsigned    m_energy;
		unsigned    m_attack;
	protected:
		bool canAct() const;
		bool isFatalDamage(unsigned int amount) const;
		bool isAlive() const;
	public:
		ClapTrap();
		ClapTrap(const std::string& n, unsigned hits = 10, unsigned energy = 10,
					unsigned attack = 0);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		virtual ~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

};

#endif
