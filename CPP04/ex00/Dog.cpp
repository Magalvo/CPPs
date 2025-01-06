#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
    type = "Dog";
    putStr("Dog constructor called\n", CYAN);
}

Dog::~Dog()
{
    putStr("Dog destructor called", CYAN);
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    putStr("Dog copy constructor called", CYAN);
    *this = copy;
}

Dog & Dog::operator=(const Dog &copy)
{
    putStr("Dog assignment operator called\n", CYAN);
    if(this != &copy)
        type = copy.type;
    return(*this);
}

void Dog::makeSound() const{
    putStr("Woooofer Ão ão!\n", CYAN);
}