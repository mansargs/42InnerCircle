#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Creating default FragTrap ===\n";
	FragTrap f1;
	f1.highFivesGuys();

	std::cout << "\n=== Creating parametrized FragTrap ===\n";
	FragTrap f2("Bob");
	f2.highFivesGuys();

	std::cout << "\n=== Copy constructing FragTrap ===\n";
	FragTrap f3(f2);
	f3.highFivesGuys();

	std::cout << "\n=== Assigning FragTrap ===\n";
	f1 = f3;
	f1.highFivesGuys();

	std::cout << "\n=== End of main ===\n";
	return 0;
}
