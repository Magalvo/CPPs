#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

class Animal
{
    protected:
    std::string type;
    public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &copy);
    Animal &operator=(const Animal &copy);
    std::string getType() const;
    virtual void makeSound() const = 0;
};

void putStr(std::string str, std::string color);
void putNum(int bits, std::string color);

#endif