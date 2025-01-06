#include "WrongCat.hpp"
#include <iostream>


WrongCat::WrongCat()
{
    type = "Wrongcat";
    putStr("WrongCat Default constructor called",CYAN);
}

WrongCat::~WrongCat()
{
    putStr("WrongCat Default destructor called",CYAN);
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
    putStr("WrongCat Copy constructor called",CYAN);
    *this = copy;
}
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    putStr("Dog assignment operator called",CYAN);
    if(this != &copy)
        type = copy.type;
        
    return(*this);
}

void WrongCat::makeSound() const
{
    putStr("Baduntssss",CYAN);
}