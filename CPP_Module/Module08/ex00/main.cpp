#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	try
	{
		// ---------- VECTOR TEST ----------
		std::vector<int> v;
		for (int i = 0; i < 5; ++i)
			v.push_back(i * 10); // 0, 10, 20, 30, 40

		std::vector<int>::const_iterator vit = easyfind(v, 20);
		std::cout << "Found in vector: " << *vit << std::endl;

		// ---------- LIST TEST ----------
		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);

		std::list<int>::const_iterator lit = easyfind(l, 2);
		std::cout << "Found in list: " << *lit << std::endl;

		// ---------- DEQUE TEST ----------
		std::deque<int> d;
		d.push_back(5);
		d.push_back(10);
		d.push_back(15);

		std::deque<int>::const_iterator dit = easyfind(d, 100);
		std::cout << "Found in deque: " << *dit << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
