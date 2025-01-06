#include "Animal.hpp"

Animal::Animal()
{
    type = "Default Animal";
    putStr("Animal constructor called\n", CYAN);
}

Animal::~Animal()
{
    putStr("Animal destrutor called\n", CYAN);
}

Animal::Animal(const Animal &copy)
{
    putStr("Animal copy constructor called\n", CYAN);
    *this=copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    putStr("Animal assignment operator called\n", CYAN);
    if(this != &copy)
        type = copy.type;
    return (*this);
}

std::string Animal::getType() const
{
    return(type);
}