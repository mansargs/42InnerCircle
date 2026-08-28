#include <iostream>
#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point inside1(5, 5);
	Point inside2(4, 3);
	Point outside1(5, 11);
	Point outside2(-1, 0);
	Point outside3(6, -1);
	Point edge1(0, 0);
	Point edge2(5, 0);
	Point edge3(7, 6);

	std::cout << std::boolalpha;
	std::cout << "inside1: " << bsp(a, b, c, inside1) << std::endl;
	std::cout << "inside2: " << bsp(a, b, c, inside2) << std::endl;
	std::cout << "outside1: " << bsp(a, b, c, outside1) << std::endl;
	std::cout << "outside2: " << bsp(a, b, c, outside2) << std::endl;
	std::cout << "outside3: " << bsp(a, b, c, outside3) << std::endl;
	std::cout << "edge1 (vertex A): " << bsp(a, b, c, edge1) << std::endl;
	std::cout << "edge2 (AB): " << bsp(a, b, c, edge2) << std::endl;
	std::cout << "edge3 (BC): " << bsp(a, b, c, edge3) << std::endl;
	return 0;
}

