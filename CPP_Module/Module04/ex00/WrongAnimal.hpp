#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

#include <string>

class WrongAnimal {
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string& t);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& ther);
		~WrongAnimal();

		void makeSound() const;
		const std::string& getType() const;
};

#endif
