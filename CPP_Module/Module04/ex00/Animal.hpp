#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string& t);
		Animal(const Animal& other);
		Animal& operator=(const Animal& ther);
		virtual ~Animal();

		virtual void makeSound() const;
		const std::string& getType() const;
};

#endif
