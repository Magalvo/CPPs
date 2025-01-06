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

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if(this != &copy)
    {
        type = copy.type;
        _brain = new Brain(*copy._brain);
     }   
    return(*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof woof" << std::endl;
}

void Dog::setIdea(std::string ideia, int index)
{
    _brain->setIdea(ideia,index);
}

std::string Dog::getIdea(int index)
{
    return(_brain->getIdea(index));
}