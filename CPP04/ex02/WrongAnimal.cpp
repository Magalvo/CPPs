#include "WrongAnimal.hpp"
#include "Animal.hpp"

WrongAnimal::WrongAnimal() {
    putStr("WrongAnimal default constructor called\n", GREEN);
	this->type = "Default";
}

WrongAnimal::~WrongAnimal() {
    putStr("WrongAnimal destructor called", RED);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

t_string WrongAnimal::getType() const {
	return (type);
}

void WrongAnimal::makeSound() const {
    putStr("Default WrongAnimal sound\n", CYAN);
}
