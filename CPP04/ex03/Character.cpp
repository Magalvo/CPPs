#include "Character.hpp"
#include "AMateria.hpp"


Character::Character()
{
    _name = "default";
    for(int index = 0; index < 4; index++)
        _materia[index] = NULL;
}

Character::Character(std::string name) : _name(name)
{
    for(int index = 0; index < 4; index++)
    {
        _materia[index] = NULL;
    }
}

Character::Character(const Character &copy)
{
    *this = copy;
}

Character &Character::operator=(const Character &copy)
{
    this->_name = copy._name;
    return *this;
}

Character::~Character()
{
    for(int index = 0; index < 4; index++)
    {
        if (_materia[index] != NULL)
            delete _materia[index];
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria *m)
{
    for(int index = 0; index < 4; index++)
    {
        if (_materia[index] == NULL)
        {
            _materia[index] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 4)
    {
        delete _materia[idx];
        _materia[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
   
    if (idx < 4 && _materia[idx] != NULL)
    {
        _materia[idx]->use(target);
    }
        
}