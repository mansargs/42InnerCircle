#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
private:
	static const int inventory_size = 4;
	static const int floor_size = 4;
	std::string m_name;
	AMateria* inventory[inventory_size];
	AMateria* floor[floor_size];
private:
	void nullifyInventories();
	void nullifyFloor();
	void cloneInventories(const Character& other);
	bool validIdx(int idx) const;
	void deleteInventories();
	void deleteFloor();
public:
	Character();
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();

	virtual std::string const& getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
