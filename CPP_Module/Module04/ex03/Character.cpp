#include "Character.hpp"
#include <iostream>

void Character::nullifyInventories() {
	for (int i = 0; i < inventory_size; ++i)
		inventory[i] = NULL;
}

void Character::nullifyFloor() {
	for (int i = 0; i < floor_size; ++i)
		floor[i] = NULL;
}

void Character::cloneInventories(const Character &other) {
	for (int i = 0; i < inventory_size; ++i) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

bool Character::validIdx(int idx) const {
	return idx >= 0 && idx < inventory_size;
}

void Character::deleteInventories() {
	for (int i = 0; i < inventory_size; ++i) {
		delete inventory[i];
		inventory[i] = NULL;
	}
}

void Character::deleteFloor() {
	for (int i = 0; i < floor_size; ++i) {
		delete floor[i];
		floor[i] = NULL;
	}
}

Character::Character() : m_name("Undefined") {
	nullifyInventories();
	nullifyFloor();
}

Character::Character(const std::string& name) : m_name(name) {
	nullifyInventories();
	nullifyFloor();
}

Character::Character(const Character& other) : m_name(other.m_name) {
	cloneInventories(other);
	nullifyFloor();
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		m_name = other.m_name;
		deleteInventories();
		deleteFloor();
		cloneInventories(other);
		nullifyFloor();
	}
	return *this;
}

Character::~Character() {
	deleteInventories();
	deleteFloor();
}

std::string const& Character::getName() const {
	return m_name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < inventory_size; ++i) {
		if (inventory[i] == m)
			return;
	}
	for (int i = 0; i < inventory_size; ++i) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (!validIdx(idx) || !inventory[idx])
		return;
	for (int i = 0; i < floor_size; ++i) {
		if (!floor[i]) {
			floor[i] = inventory[idx];
			inventory[idx] = NULL;
			return;
		}
	}
}

void Character::use(int idx, ICharacter& target) {
	if (validIdx(idx) && inventory[idx])
		inventory[idx]->use(target);
}
