#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain Default Destuctor called" << std::endl;
}

Brain::Brain(std::string myideas[100])
{
    for(int i = 0; i < 100; i++)
        ideas[i] = myideas[i];
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

//?Assignment operator
Brain &Brain::operator=(const Brain &copy)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if(this != &copy)
    {
       for(int i = 0; i < 100; i++)
            ideas[i] = copy.ideas[i];
    }
    return(*this);
}

//?setter
void Brain::setIdea(std::string idea, int index)
{
    if(!(index >= 100 || index < 0))
    {
        ideas[index] = idea;
        std::cout << "Saved Idea" << std::endl;
        return;
    }   
    std::cout << "Index Incorret please send a correct index" << std::endl;
}

//?getter
std::string Brain::getIdea(int index)
{
    if(!(index >= 100 || index < 0))
    {
        if(!ideas[index].empty())
            return(ideas[index]);
    } 
    return("Index Incorret or Empty please send a correct index");
}