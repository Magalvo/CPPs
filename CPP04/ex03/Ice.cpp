#include "Ice.hpp"

Ice::Ice() : AMateria(){
	_type = "ice";
}

Ice::Ice(const Ice &src) : AMateria(){
	*this = src;
}

Ice::~Ice() {
	
}

Ice& Ice::operator=(const Ice &src) {
	_type = src._type;
	return *this;
}

void Ice::use(ICharacter &target) {
	putStr("* ", RESET);
	putStr("shoots", RED_BLINK);
	putStr(" ❄️  an ice bolt at ", CYAN_BOLD);
	putStr(target.getName(), MAGENTA);
	putStr(" *\n", RESET);
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}
