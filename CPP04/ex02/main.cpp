/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:48:09 by dde-maga          #+#    #+#             */
/*   Updated: 2024/12/28 15:48:09 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongCat.hpp"

void putStr(std::string str, std::string color){
	std::cout << color << str << RESET;
}

void putNum(int bits, std::string color){
	std::cout << color << bits << RESET;
}

int main()
{
Animal* Mimosa = new Dog();
Animal* Tina = new Cat();
putStr("===========\n", RESET);
putStr(" MIMOSA \n", YELLOW);
putStr(Mimosa->getType(), GREEN);
putStr(" ", RESET);
Mimosa->makeSound();
putStr("===========\n", RESET);
putStr(" TINA \n", YELLOW);
putStr(Tina->getType(), GREEN);
putStr(" ", RESET);
Tina->makeSound();
putStr("===========\n\n\n", RESET);

Animal* Galinha = new Dog();
putStr("===========\n", RESET);
putStr(" GALINHA \n", YELLOW);
putStr(Galinha->getType(), GREEN);
putStr(" ", RESET);
Galinha->makeSound();
putStr("===========\n", RESET);

delete Mimosa;
delete Tina;
delete Galinha;
return (0);
}
