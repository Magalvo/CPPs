#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() {
    putStr("Wrong Animal Default constructor called\n", GREEN);
}

WrongAnimal::~WrongAnimal(){
    putStr("Wrong Animal destrutor called\n", RED);
}


WrongAnimal::WrongAnimal(const WrongAnimal &copy){
    putStr("Wrong Animal copy constructor called\n", CYAN);
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy){
    putStr("Wrong Animal assignment operator called\n", CYAN);
    if(this != &copy)
        type = copy.type;
    return(*this);
}

std::string WrongAnimal::getType() const{
    return(type);
}

void WrongAnimal::makeSound() const{
    putStr("BipBop That sounds wrong\n", CYAN);
}