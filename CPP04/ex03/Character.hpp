#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
    std::string _name;
    AMateria *_materia[4];

public:
    Character();
    Character(const Character &copy);
    Character &operator=(const Character &copy);
    Character(std::string name);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};



#endif