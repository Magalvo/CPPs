#include "AMateria.hpp"

void putStr(std::string str, std::string color){
	std::cout << color << str << RESET;
}

void putNum(int bits, std::string color){
	std::cout << color << bits << RESET;
}

AMateria::AMateria() {
}

AMateria::~AMateria() {
}

AMateria::AMateria(const AMateria &other) {
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
	(void)other;
	return *this;
}

void AMateria::use(ICharacter &target) {
	(void)target;
}

std::string const &AMateria::getType() const {
	return _type;
}