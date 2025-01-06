#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"
#include <string>
#include "ICharacter.hpp"

class Cure : public AMateria
{
    protected:

    public:
    Cure();
    Cure(std::string const & type);
    Cure(const Cure &copy);
    Cure &operator=(const Cure &copy);
    AMateria* clone() const;
    void use(ICharacter& target);
    ~Cure();
    
};

#endif