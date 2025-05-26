#include "Serializer.hpp"

Serializer::Serializer() {
    putStr("Default constructor called\n", GREEN);
}

Serializer::~Serializer() {
    putStr("Destructor called\n", GREEN);
}

Serializer::Serializer(const Serializer &other) {
	*this = other;
}

Serializer &Serializer::operator=(const Serializer &other) {
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

void putStr(const std::string &str, const std::string &color) {
    std::cout << color << str << RESET;
}

void putNum(int bits, const std::string &color) {
    std::cout << color << bits << RESET;
}

void putErr(const std::string &str, const std::string &color) {
    std::cerr << color << str << RESET;
}
