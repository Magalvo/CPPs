#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal() {
    putStr( "Dog default constructor called\n",GREEN);
	this->type = "Dog";
	_brain = new Brain();
}

Dog::~Dog() {
    putStr("Dog destructor called\n", RED);
	delete _brain;
}

Dog::Dog(const Dog &other) : Animal() {
    putStr( "Dog copy constructor called\n", CYAN);
	this->type = other.type;
	this->_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other) {
	if (this == &other)
		return *this;
	delete this->_brain;
	this->_brain = new Brain(*other._brain);
	this->Animal::operator=(other);
	return *this;
}

void Dog::makeSound() const {
    putStr( "Woof woof\n", MAGENTA);
}

Brain *Dog::getBrain() const {
	return _brain;
}