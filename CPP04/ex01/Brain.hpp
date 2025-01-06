#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
    private:
    std::string ideas[100];
    public:
    Brain();
    Brain(std::string myideas[100]);
    ~Brain();
    Brain(const Brain &copy);
    Brain &operator=(const Brain &copy);
    void setIdea(std::string idea, int index);
    std::string getIdea(int index);
};

#endif