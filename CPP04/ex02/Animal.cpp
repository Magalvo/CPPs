#include "Animal.hpp"

Animal::Animal(){
    type = "Default Animal";
    putStr("Animal constructor called\n", CYAN);
}

Animal::~Animal(){
    putStr("Animal destrutor called\n", RED);
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

t_string Animal::getType() const
{
    return(type);
}