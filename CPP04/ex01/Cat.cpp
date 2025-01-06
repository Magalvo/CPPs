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

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if(this != &copy)
    {
        _brain = new Brain(*copy._brain);
        type = copy.type;
    }
    return(*this);
}

void Cat::makeSound() const
{
    std::cout << "Meow meow" << std::endl;
}

void Cat::setIdea(std::string ideia, int index)
{
    _brain->setIdea(ideia,index);
}

std::string Cat::getIdea(int index)
{
    return(_brain->getIdea(index));
}