#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>


AMateria::AMateria()
{
    _type = "default";
    // std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::~AMateria()
{
    // std::cout << "AMateria Default destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
    //  std::cout << "AMateria copy constructor called" << std::endl;
    *this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
    // std::cout << "AMateria assignment operator called" << std::endl;
    if(this != &copy)
    {
        _type = copy._type;
    }
        
    return(*this);
}

AMateria::AMateria(std::string const & type)
{
    _type = type;
}

const std::string& AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    if(target.getName() == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    else if(target.getName() == "cure")
        std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}