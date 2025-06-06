#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include "Animal.hpp"

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    ~WrongCat();
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &copy);
    void makeSound() const;

};

#endif