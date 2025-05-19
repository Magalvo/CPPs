#include "WrongCat.hpp"
#include <iostream>
#include "Animal.hpp"


WrongCat::WrongCat()
{
    putStr("WrongCat Default constructor called", GREEN);
    type = "Wrongcat";
    _brain = new Brain();
}

WrongCat::~WrongCat()
{
    putStr("WrongCat Default destructor called", RED);
    delete _brain;
}

WrongCat::WrongCat(const WrongCat &copy) : Animal(copy)
{
    putStr("WrongCat Copy constructor called", CYAN);
    *this = copy;
}
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    putStr("Dog assignment operator called\n", CYAN);
    if(this != &copy)
    {
        _brain = new Brain(*copy._brain);
        type = copy.type;
    }   
    return(*this);
}


void WrongCat::setIdea(std::string ideia, int index)
{
    _brain->setIdea(ideia,index);
}

std::string WrongCat::getIdea(int index)
{
    return(_brain->getIdea(index));
}