#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void increment(T& x)
{
	x++;
}

template <typename T>
void print(const T& x)
{
	std::cout << x << " ";
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = 5;

	std::cout << "Original int array: ";
	iter(arr, len, print<int>);
	std::cout << std::endl;

	iter(arr, len, increment<int>);

	std::cout << "After increment: ";
	iter(arr, len, print<int>);
	std::cout << std::endl;

	const std::string strs[] = {"Hello", "Iter", "Template"};

	std::cout << "Const string array: ";
	iter(strs, 3, print<std::string>);
	std::cout << std::endl;

	return 0;
}
