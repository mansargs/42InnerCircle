#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
	private:
		std::string m_name;
	public:
		DiamondTrap();
		DiamondTrap(const std::string &n, unsigned hits = 100,
						unsigned energy = 50, unsigned attack = 30);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();

		void attack(const std::string &target);
		void whoAmI();
};

#endif
