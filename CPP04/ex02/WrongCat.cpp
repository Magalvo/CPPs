#include "WrongCat.hpp"
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"


WrongCat::WrongCat(){
    putStr("WrongCat Default constructor called\n", GREEN);
    type = "Wrongcat";
    _brain = new Brain();
}

WrongCat::~WrongCat(){
    putStr("WrongCat Default destructor called", RED);
    delete _brain;
}

WrongCat::WrongCat(const WrongCat &copy) : Animal(copy){
    putStr("WrongCat Copy constructor called\n", CYAN_BOLD);
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
    putStr("WrongCat assignment operator called\n", CYAN_BOLD);
    if(this != &copy)
    {
        _brain = new Brain(*copy._brain);
        type = copy.type;
    }   
    return(*this);
}

void WrongCat::setIdea(std::string ideia, int index){
    _brain->setIdea(ideia,index);
}

t_string WrongCat::getIdea(int index){
    return(_brain->getIdea(index));
}