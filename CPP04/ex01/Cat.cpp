#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal(){
    putStr("Cat constructor called\n", CYAN);
    type = "Cat";
    _brain = new Brain();
}

Cat::~Cat(){
    putStr("Cat destructor called\n", RED);
    delete _brain;
}

Cat::Cat(const Cat &copy) : Animal(copy){
    putStr("Cat copy constructor called\n", CYAN);
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy){
    putStr("Cat assignment operator called\n", CYAN);
    if(this != &copy)
    {
        _brain = new Brain(*copy._brain);
        type = copy.type;
    }
    return(*this);
}

void Cat::makeSound() const{
    putStr("Meaow Meaow\n", MAGENTA);
}

void Cat::setIdea(std::string idea, int index){
    _brain->setIdea(idea,index);
}

std::string Cat::getIdea(int index){
    return(_brain->getIdea(index));
}