#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
    type = "Cat";
    putStr("Cat constructor called\n", CYAN);
}

Cat::~Cat()
{
    putStr("Cat destructor called", CYAN);
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    putStr("Cat copy constructor called", CYAN);
    *this = copy;
}

Cat & Cat::operator=(const Cat &copy)
{
    putStr("Cat assignment operator called\n", CYAN);
    if(this != &copy)
        type = copy.type;
    return(*this);
}

void Cat::makeSound() const{
    putStr("Meaooooow\n", CYAN);
}