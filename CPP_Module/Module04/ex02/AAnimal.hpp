#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class AAnimal {
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const std::string& t);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& ther);
		virtual ~AAnimal();

		virtual void makeSound() const = 0;
		const std::string& getType() const;
};

#endif
