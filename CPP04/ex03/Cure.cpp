#include "Cure.hpp"

Cure::Cure() : AMateria() {
	_type = "cure";
}

Cure::Cure(const Cure &src) : AMateria() {
	*this = src;
}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure &src) {
	_type = src._type;
	return (*this);
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	putStr("* ", RESET);
	putStr("heals ❤️  ", GREEN_BLINK);
	putStr(target.getName(), CYAN_BOLD);
	putStr("'s wounds * \n", CYAN);
}