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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


void putStr(std::string str, std::string color){
	std::cout << color << str << RESET;
}

void putNum(int bits, std::string color){
	std::cout << color << bits << RESET;
}

int main()
{
const Animal* Mimosa = new Animal();
const Animal* Xispe = new Dog();
const Animal* Tarix = new Cat();

//?Animal
putStr(Mimosa->getType() , RESET);
putStr("\n********\n", RESET);
Mimosa->makeSound();
putStr("********\n\n", RESET);
//?Dog
putStr(Xispe->getType() , RESET);
putStr("\n********\n", RESET);
Xispe->makeSound();
putStr("********\n\n", RESET);

//?Cat
putStr(Tarix->getType() , RESET);
putStr("\n********\n", RESET);
Tarix->makeSound();
putStr("********\n\n", RESET);

//?WrongAnimal
WrongAnimal* Thanos = new WrongCat();
putStr(Thanos->getType() , RESET);
putStr("\n********\n", RESET);
Thanos->makeSound();
putStr("********\n\n", RESET);

//! For dynamically allocated objects, the destructor is not called automatically unless delete is used.
delete Mimosa;
delete Xispe;
delete Tarix;
delete Thanos;
return (0);
}

