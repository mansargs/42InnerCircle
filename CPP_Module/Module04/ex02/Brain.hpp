#ifndef BRAIN_H
# define BRAIN_H

# include <string>

class Brain {
	private:
		static const int ideas_size = 100;
		std::string ideas[ideas_size];
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
};

#endif
