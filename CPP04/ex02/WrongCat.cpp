#include "WrongCat.hpp"
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"


WrongCat::WrongCat()
{
    std::cout << "WrongCat Default constructor called" << std::endl;
    type = "Wrongcat";
    _brain = new Brain();
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Default destructor called" << std::endl;
    delete _brain;
}

WrongCat::WrongCat(const WrongCat &copy) : Animal(copy)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = copy;
}
WrongCat &WrongCat::operator=(const WrongCat &copy)
{
   std::cout << "Dog assignment operator called" << std::endl;
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