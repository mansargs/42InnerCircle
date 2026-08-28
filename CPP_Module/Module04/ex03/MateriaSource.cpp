#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < storage_size; ++i)
		m_storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < storage_size; ++i)
		m_storage[i] = other.m_storage[i]
			? other.m_storage[i]->clone()
			: NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < storage_size; ++i) {
			delete m_storage[i];
			m_storage[i] = other.m_storage[i]
				? other.m_storage[i]->clone()
				: NULL;
		}
	}
	return *this;
}


MateriaSource::~MateriaSource() {
	for (int i = 0; i < storage_size; ++i)
		delete m_storage[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;

	for (int i = 0; i < storage_size; ++i) {
		if (m_storage[i] == NULL) {
			m_storage[i] = m; // take ownership of the passed pointer
			return;
		}
	}

	// if storage is full we must not leak the passed materia
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < storage_size; ++i) {
		if (m_storage[i] && m_storage[i]->getType() == type)
			return m_storage[i]->clone();
	}
	return NULL;
}
