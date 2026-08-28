#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "========== BASIC CONSTRUCTION ==========\n";
    ClapTrap a("Alpha");
    std::cout << "\n========== BASIC ATTACK ==========\n";
    a.attack("TargetDummy");
    std::cout << "\n========== TAKE DAMAGE ==========\n";
    a.takeDamage(3);
    a.takeDamage(4);
    std::cout << "\n========== REPAIR ==========\n";
    a.beRepaired(5);
    std::cout << "\n========== ENERGY DRAIN ==========\n";
    ClapTrap b("Beta");
    for (int i = 0; i < 11; i++)
        b.attack("Wall");
    std::cout << "\n========== TRY REPAIR WITH NO ENERGY ==========\n";
    b.beRepaired(5);
    std::cout << "\n========== HP DEPLETION ==========\n";
    ClapTrap c("Charlie");
    c.takeDamage(5);
    c.takeDamage(10);
    std::cout << "\n========== TRY ACTIONS WITH 0 HP ==========\n";
    c.attack("Ghost");
    c.beRepaired(10);
    std::cout << "\n========== MULTIPLE OBJECTS ==========\n";
    ClapTrap d("Delta");
    ClapTrap e("Echo");
    d.attack("Echo");
    e.takeDamage(2);
    std::cout << "\n========== END OF TESTS ==========\n";
    return 0;
}
