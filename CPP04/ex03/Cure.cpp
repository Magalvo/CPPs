#include "Cure.hpp"
#include "AMateria.hpp"

#include <iostream>


Cure::Cure() : AMateria("cure")
{
    // std::cout << "Cure Default constructor called" << std::endl;
}

Cure::~Cure() 
{
    // std::cout << "Cure Default destructor called" << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{    
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
    *this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
    // std::cout << "Cure assignment operator called" << std::endl;
    (void)copy;
    return(*this);
}

AMateria* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}