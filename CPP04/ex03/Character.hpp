#ifndef Character_HPP
#define Character_HPP

#include "ICharacter.hpp"
#include <iostream>

//? Derived class
class Character : public ICharacter{
	private:
		std::string _name;
		AMateria *_materia[4];

	public:
		Character();
		Character(const std::string &name);
		Character(const Character &src);
		~Character();
		Character &operator=(const Character &src);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
};
#endif