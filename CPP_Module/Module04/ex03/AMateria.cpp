#include "AMateria.hpp"

AMateria::AMateria() : m_type("Undefined") {}

AMateria::AMateria(std::string const & type) : m_type(type) {}

AMateria::AMateria(const AMateria& other) : m_type(other.m_type) {}

AMateria& AMateria::operator=(const AMateria& other) {
	static_cast<void> (other);
	return *this;
}
AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
	return m_type;
}

void AMateria::use(ICharacter& target) {
	static_cast<void>(target);
}
