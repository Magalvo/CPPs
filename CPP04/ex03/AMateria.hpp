#ifndef AMateria_HPP
# define AMateria_HPP

# include <iostream>
# include "ICharacter.hpp"

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define RED_BLINK "\033[1;31;5m"
#define GREEN "\033[1;32m"
#define GREEN_BLINK "\033[1;32;5m"
#define YELLOW "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define CYAN_BOLD "\033[1;36m"
#define CYAN "\033[0;36m"

typedef std::string t_string;
class ICharacter;

//? Base class
class AMateria {
	protected:
		t_string _type;
		
	public:
		AMateria();
		AMateria(t_string const &type);
		virtual ~AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		t_string const &getType() const;
		//? pure virtual function providing interface framework.
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};

void putStr(t_string str, t_string color);
void putNum(int bits, t_string color);

#endif