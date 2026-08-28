#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>
#include <vector>
#include <iostream>


class PmergeMe {
	private:
		std::vector<int> deq;
		std::list<int> lst;

		void printMessage(int n, const std::string& container, double time) const;
		template<typename Iterator>
		void printContainer(Iterator beg, Iterator end) const{
			for (; beg != end; ++beg)
				std::cout << *beg << " ";
			std::cout << std::endl;
		}

		void smartInsertionVector(std::vector<int>& sorted, const std::vector<int>& smalls) const;
		void smartInsertionList(std::list<int>& sorted, const std::list<int>& smalls) const;
		void fordJonsonVector(std::vector<int>& container) const;
		void fordJonsonList(std::list<int>& container) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		static std::vector<int> generateJacobsthalOrder(size_t n);
		bool argvValidation(int ac, char *av[]) const;
		void parsArgv(int ac, char *av[]);
		void run();
};

#endif
