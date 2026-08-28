#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
	Data d;
	Data* ptr = &d;

	uintptr_t raw = Serializer::serialize(ptr);
	std::cout << "Serialized: " << raw << std::endl;

	Data* newPtr = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer == original? "
			  << (newPtr == ptr ? "Yes" : "No") << std::endl;
	return 0;
}
