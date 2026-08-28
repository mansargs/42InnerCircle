#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "\n===== CONSTRUCTION =====\n";
	DiamondTrap d("DiamondBob");
	std::cout << "\n===== WHO AM I =====\n";
	d.whoAmI();
	std::cout << "\n===== ATTACK BEHAVIOR =====\n";
	d.attack("TargetDummy");
	std::cout << "\n===== ENERGY SOURCE TEST =====\n";
	for (int i = 0; i < 55; ++i)
		d.attack("EnergyDrain");
	std::cout << "\n===== HP SOURCE TEST =====\n";
	d.takeDamage(90);
	d.attack("StillAlive");
	d.takeDamage(20);  
	d.attack("ShouldNotAttack");
	std::cout << "\n===== COPY TEST =====\n";
	DiamondTrap copy(d);
	copy.whoAmI();
	copy.attack("CopyTarget");
	std::cout << "\n===== ASSIGNMENT TEST =====\n";
	DiamondTrap assign("Temp");
	assign = d;
	assign.whoAmI();
	std::cout << "\n===== END =====\n";
	return 0;
}
