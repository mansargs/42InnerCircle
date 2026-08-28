#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Creating a ClapTrap ===\n";
	ClapTrap c1("CL4P-TP");
	c1.attack("target1");
	c1.takeDamage(10);
	c1.beRepaired(5);
	
	std::cout << "\n=== Creating a ScavTrap ===\n";
	ScavTrap s1("SC4V-TP");
	s1.attack("target2");
	s1.takeDamage(20);
	s1.beRepaired(10);
	s1.guardGate();

	std::cout << "\n=== Copying a ScavTrap ===\n";
	ScavTrap s2(s1);
	s2.attack("target3");
	s2.guardGate();
	std::cout << "\n=== Assigning a ScavTrap ===\n";
	ScavTrap s3("Temporary");
	s3 = s1;
	s3.attack("target4");
	s3.guardGate();
	std::cout << "\n=== Destruction sequence ===\n";
	return 0;
}
