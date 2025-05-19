#include "Brain.hpp"
#include <iostream>

Brain::Brain(){
    putStr("Brain Default Constructor called\n", GREEN);
}

Brain::~Brain(){
    putStr("Brain Default Destuctor called\n", RED);
}

Brain::Brain(std::string myideas[100]){
    for(int i = 0; i < 100; i++)
        ideas[i] = myideas[i];
}

Brain::Brain(const Brain &copy){
    putStr("Brain copy constructor called\n", GREEN);
    *this = copy;
}

//?Assignment operator
Brain &Brain::operator=(const Brain &copy){
    putStr("Brain assignment operator called\n", CYAN_BOLD);
    if(this != &copy)
    {
       for(int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    }
    return(*this);
}

//?setter
void Brain::setIdea(std::string idea, int index){
    if(!(index >= 100 || index < 0))
    {
        ideas[index] = idea;
        putStr("Saved Idea\n", MAGENTA);
        return;
    }
    putStr("Index Incorret please send a correct index\n", CYAN_BOLD);
}

//?getter
t_string Brain::getIdea(int index){
    if(!(index >= 100 || index < 0))
    {
        if(!ideas[index].empty())
            return(ideas[index]);
    } 
    return("Index Incorret or Empty please send a correct index\n");
}