#include "Data.hpp"

Data::Data() : x(0), y(0.0) {}

Data::Data(const Data& other) {
	static_cast<void>(other);
}

Data& Data::operator=(const Data& other) {
	static_cast<void>(other);
	return *this;
}

Data::~Data() {}

