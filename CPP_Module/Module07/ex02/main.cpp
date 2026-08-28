#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Array.hpp"

static const int max_value = 30;

int main()
{
	try
	{
		Array<int> numbers(max_value);
		int* mirror = NULL;

		try
		{
			mirror = new int[max_value];
		}
		catch (const std::bad_alloc& e)
		{
			std::cerr << "Failed to allocate mirror array: " << e.what() << std::endl;
			return 1;
		}
		srand(static_cast<unsigned int>(time(NULL)));

		for (int i = 0; i < max_value; ++i)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}
		for (int i = 0; i < max_value; ++i)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "Error: values differ at index " << i << std::endl;
				delete[] mirror;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Exception caught (negative index): " << e.what() << '\n';
		}
		try
		{
			numbers[max_value] = 0;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Exception caught (overflow index): " << e.what() << '\n';
		}
		for (int i = 0; i < max_value; ++i)
		{
			numbers[i] = rand();
			std::cout << numbers[i] << '\t';
		}
		std::cout << std::endl;
		delete[] mirror;
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		return 1;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
		return 1;
	}
	std::cout << "All tests passed successfully!" << std::endl;
	return 0;
}
