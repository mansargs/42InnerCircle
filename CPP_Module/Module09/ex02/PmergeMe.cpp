#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>
#include <set>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : deq(other.deq), lst(other.lst) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		deq = other.deq;
		lst = other.lst;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printMessage(int n, const std::string& container, double time) const {
	std::cout << "Time to process a range of " << n << " elements with std::" << container << " : " << time << " us" << std::endl;
}

bool PmergeMe::argvValidation(int ac, char *av[]) const {
	std::set<int> seen;

	if (ac == 1)
		return false;
	for (int i = 1; i < ac; ++i) {
		int j = 0;
		while (av[i][j]) {
			if (!std::isdigit(av[i][j]))
				return false;
			++j;
		}
		long val = std::strtol(av[i], NULL, 10);
		if (val <= 0 || val > std::numeric_limits<int>::max())
			return false;
		if (!seen.insert(static_cast<int>(val)).second)
			return false;
	}
	return true;
}

void PmergeMe::parsArgv(int ac, char *av[]) {
	for (int i = 1 ; i < ac; ++i) {
		int val = std::atoi(av[i]);
		deq.push_back(val);
		lst.push_back(val);
	}
}

std::vector<int> PmergeMe::generateJacobsthalOrder(size_t n) {
	std::vector<int> order;
	if (n == 0)
		return order;
	order.push_back(0);
	if (n == 1)
		return order;

	size_t j = 1;
	while (j < n) {
		order.push_back(j);
		j = 2 * order.back() + 1;
	}
	for (size_t i = 0; i < n; ++i) {
		bool found = false;
		for (size_t k = 0; k < order.size(); ++k) {
			if (static_cast<size_t>(order[k]) == i) {
				found = true;
				break;
			}
		}
		if (!found)
			order.push_back(i);
	}
	return order;
}

void PmergeMe::smartInsertionVector(std::vector<int>& sorted, const std::vector<int>& smalls) const{
	std::vector<int> order = PmergeMe::generateJacobsthalOrder(smalls.size());

	for (size_t i = 0; i < smalls.size(); ++i) {
		int val = smalls[order[i]];

		std::vector<int>::iterator left = sorted.begin();
		std::vector<int>::iterator right = sorted.end();
		while (left != right) {
			std::vector<int>::iterator mid = left + (right - left) / 2;
			if (*mid < val)
				left = mid + 1;
			else
				right = mid;
		}
		sorted.insert(left, val);
	}
}

void PmergeMe::fordJonsonVector(std::vector<int>& container) const{
	std::vector<int> bigs, smalls;

	if (container.size() <= 1)
		return ;
	for (size_t i = 0; i < container.size(); i += 2) {
		if (i + 1 < container.size()) {
			int a = container[i];
			int b = container[i + 1];
			if (a > b)
				std::swap(a, b);
			smalls.push_back(a);
			bigs.push_back(b);
		} else {
			smalls.push_back(container[i]);
		}
	}

	fordJonsonVector(bigs);
	smartInsertionVector(bigs, smalls);
	container = bigs;
}

void PmergeMe::smartInsertionList(std::list<int>& sorted, const std::list<int>& smalls) const {
	std::vector<int> order = generateJacobsthalOrder(smalls.size());
	std::list<int>::const_iterator sit;
	for (size_t idx = 0; idx < order.size(); ++idx) {
		sit = smalls.begin();
		std::advance(sit, order[idx]);
		int val = *sit;

		std::list<int>::iterator it = sorted.begin();
		while (it != sorted.end() && *it < val) ++it;
		sorted.insert(it, val);
	}
}

void PmergeMe::fordJonsonList(std::list<int>& container) const {
	if (container.size() <= 1) return;

	std::list<int> bigs, smalls;
	std::list<int>::const_iterator it = container.begin();
	while (it != container.end()) {
		int a = *it;
		++it;
		if (it != container.end()) {
			int b = *it;
			++it;
			if (a > b) std::swap(a, b);
			smalls.push_back(a);
			bigs.push_back(b);
		} else {
			smalls.push_back(a);
		}
	}

	fordJonsonList(bigs);
	smartInsertionList(bigs, smalls);
	container = bigs;
}

void PmergeMe::run() {
	std::cout << "Before: ";
	printContainer(deq.begin(), deq.end());

	std::vector<int> deqCopy = deq;
	std::list<int>  lstCopy = lst;

	clock_t startvector = clock();
	fordJonsonVector(deqCopy);
	clock_t endvector = clock();

	clock_t startList = clock();
	fordJonsonList(lstCopy);
	clock_t endList = clock();

	std::cout << "After: ";
	printContainer(deqCopy.begin(), deqCopy.end());

	double timevector = (double)(endvector - startvector) / CLOCKS_PER_SEC * 1e6;
	double timeList  = (double)(endList - startList) / CLOCKS_PER_SEC * 1e6;
	printMessage(deqCopy.size(), "vector", timevector);
	printMessage(lstCopy.size(), "list", timeList);
}

