#include "WrongAnimal.hpp"

#include <iostream>
#include <string>

WrongAnimal::~WrongAnimal()
{
    putStr("Wrong Animal destrutor called", CYAN);
}

WrongAnimal::WrongAnimal() 
{
    putStr("Wrong Animal Default constructor called", CYAN);
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    putStr("Wrong Animal copy constructor called", CYAN);
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    putStr("Wrong Animal assignment operator called", CYAN);
    if(this != &copy)
        type = copy.type;
    return(*this);
}

std::string WrongAnimal::getType() const
{
    return(type);
}

void WrongAnimal::makeSound() const
{
    putStr("(in silence)", CYAN);
}