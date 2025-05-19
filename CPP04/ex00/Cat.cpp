#include "Cat.hpp"

Cat::Cat() : Animal(){
    type = "Cat";
    putStr("Cat constructor called\n", CYAN);
}

Cat::~Cat(){
    putStr("Cat destructor called\n", RED);
}

Cat::Cat(const Cat &copy) : Animal(){
    putStr("Cat copy constructor called\n", CYAN);
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy){
    putStr("Cat assignment operator called\n", CYAN);
    if (this != &copy)
		type = copy.type;
	return (*this);
}

void Cat::makeSound() const{
    putStr("Meaooooow\n", MAGENTA);
}