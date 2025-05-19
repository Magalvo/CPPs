#include "Dog.hpp"
#include "Animal.hpp"

#include <iostream>

Dog::Dog() : Animal()
{
    putStr("Dog constructor called",CYAN);
    type = "Dog";
    _brain = new Brain();
}

Dog::~Dog()
{
    putStr("Dog destructor called\n", RED);
    delete _brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    putStr("Dog copy constructor called\n", CYAN);
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    putStr("Dog assignment operator called\n", CYAN);
    if(this != &copy)
    {
        type = copy.type;
        _brain = new Brain(*copy._brain);
     }   
    return(*this);
}

void Dog::makeSound() const
{
    putStr("Woof woof\n", MAGENTA);
}

void Dog::setIdea(std::string ideia, int index)
{
    _brain->setIdea(ideia,index);
}

std::string Dog::getIdea(int index)
{
    return(_brain->getIdea(index));
}