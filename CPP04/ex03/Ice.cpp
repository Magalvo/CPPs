#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(std::string const & type) : AMateria(type)
{
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
    *this = copy;
}

Ice &Ice::operator=(const Ice &copy)
{
    (void) copy;
    return (*this);
}

AMateria* Ice::clone() const
{
    Ice *clone = new Ice(*this);
    return (clone);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
}