#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(){
    type = "Wrongcat";
    putStr("WrongCat Default constructor called\n",GREEN);
}

WrongCat::~WrongCat(){
    putStr("WrongCat Default destructor called\n",RED);
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy){
    putStr("WrongCat Copy constructor called\n",CYAN);
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy){
    putStr("Dog assignment operator called\n",CYAN);
    if(this != &copy)
        type = copy.type;
        
    return(*this);
}

void WrongCat::makeSound() const{
    putStr("Baduntssss\n",CYAN);
}