#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

class WrongCat : public Animal
{
    private:
    Brain *_brain;
    public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &copy);

    void setIdea(std::string ideia,int index);
    std::string getIdea(int index);
};

#endif