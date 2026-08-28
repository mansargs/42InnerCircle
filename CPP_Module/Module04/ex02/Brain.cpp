#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain default ctor called\n";
}

Brain::Brain(const Brain& other) {
	for (int i = 0; i < ideas_size; ++i) {
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain copy ctor called\n";
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < ideas_size; ++i) {
		ideas[i] = other.ideas[i];
		}
	}
	std::cout << "Brain copy assignment called\n";
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain dtor called\n";
}

