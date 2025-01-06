#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    Ice *digin = new Ice();

    Ice *digin2 = new Ice(*digin);

    std::cout << digin2->getType() << std::endl;

    std::cout << "***********************************" << std::endl;
    ICharacter *Elsa = new Character("Elsa");
    AMateria *tmp;
    tmp = src->createMateria("ice");
    Elsa->equip(tmp);
    tmp = src->createMateria("cure");
    Elsa->equip(tmp);
    ICharacter *Sven = new Character("Sven");
    Elsa->use(0, *Sven);
    Elsa->use(1, *Sven);
    delete digin2;
    delete digin;
    delete Sven;
    delete Elsa;
    delete src;
    return 0;
}
