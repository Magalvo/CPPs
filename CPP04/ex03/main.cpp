#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

//? object-oriented principles in C++ with polymorphism, dynamic memory allocation, and virtual functions | "Interfaces" Abstract

//? An interface describes the behavior or capabilities of a C++ class 
//? without committing to a particular implementation of that class.
//? abstract classes != data abstarction
int main()
{
	{
		//? (new) alocates heap memory (stack NOT flexible / heap IS flexible)
		IMateriaSource* magicSrc = new MateriaSource();
		magicSrc->learnMateria(new Ice());
		magicSrc->learnMateria(new Cure());
		ICharacter* Elsa = new Character("Elsa");
		
		AMateria* tmp;
		tmp = magicSrc->createMateria("ice");
		Elsa->equip(tmp);
		tmp = magicSrc->createMateria("cure");
		Elsa->equip(tmp);

		ICharacter* Olaf = new Character("Olaf");
		Elsa->use(0, *Olaf);
		Elsa->use(1, *Olaf);

		delete Olaf;
		delete Elsa;
		delete magicSrc;
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		//? Test learning more than 4 materias
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());

		//? Test creating a materia of unknown type
		AMateria* unknown = src->createMateria("unknown");
		if (unknown == NULL)
			putStr("Unknown materia type correctly handled\n", RED);

		ICharacter* me = new Character("me");
		AMateria* tmp[10];

		//? Test equipping more than 4 materias
		for (int ctd = 0; ctd < 5; ctd++) {
			if (ctd < 2)
				tmp[ctd] = src->createMateria("cure");
			else
				tmp[ctd] = src->createMateria("ice");
			me->equip(tmp[ctd]);
		}

		//? Test unequipping a materia
		me->unequip(0);
		delete tmp[0];

		//? Test using a materia in an empty slot
		ICharacter* bob = new Character("bob");
		for (int ctd = 0; ctd < 4; ctd++)
        	me->use(ctd, *bob);

		//? Test using a materia in an invalid slot
		me->use(4, *bob);

		//! For dynamically allocated objects, the destructor is not called automatically unless delete is used.
		delete bob;
		delete me;
		delete src;
	}
}

