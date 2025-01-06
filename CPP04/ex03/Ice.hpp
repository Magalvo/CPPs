#ifndef ICE_HPP 
#define ICE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    protected:

    public:
    Ice();
    Ice(std::string const & type);
    Ice(const Ice &copy);
    Ice &operator=(const Ice &copy);
    AMateria* clone() const;
    void use(ICharacter& target);
    ~Ice();
    
};



#endif